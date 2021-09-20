#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smp0_tests.h"

#define LENGTH(s) (sizeof(s) / sizeof(*s))

/* Structures */
typedef struct {
  char *word;
  int counter;
} WordCountEntry;


int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0;
  char buffer[30];
  char* token;//

  while (fgets(buffer, sizeof(buffer), stdin)) {
      buffer[strlen(buffer) - 1] = '\0';
      if (*buffer == '.')
          break;
      token = strtok(buffer, " ");
      while (token != NULL) {
          int i = 0;
          if (*token == '.')
              return line_count;
          while (i < entry_count) {
              if (!strcmp(entries[i].word, token)) entries[i].counter++;
              i++;
          }
          line_count++;
          token = strtok(NULL, " ");
      }
  }
  return line_count;
}


void print_result(WordCountEntry entries[], int entry_count)
{
  fprintf(stdout, "Result:\n");
  int i = 0;
  while (i < entry_count) {
    fprintf(stdout, "%s:%d\n", entries[i].word, entries[i].counter);
    i++;
  }
}

void savefile_result(WordCountEntry entries[], int entry_count)
{
    FILE* fp = fopen("countResult.txt", "w");
    if (fp == NULL) {
        fprintf(stdout, "file open fail\n");
        return;
    }
    fprintf(fp, "Result:\n");
    int i = 0;
    while (i < entry_count) {
        fprintf(fp, "%s:%d\n", entries[i].word, entries[i].counter);
        i++;
    }
    fclose(fp);
    fprintf(stdout, "save file!\n");
}

void printHelp(const char *name)
{
  fprintf(stdout, "usage: %s [-h] <word1> ... <wordN>\n", name);
}


int main(int argc, char **argv)
{
  const char *prog_name = *argv;

  WordCountEntry entries[argc-1];
  int entryCount = 0;
  int checkfile = 0;
  argv++;

  while (*argv != NULL) {
    if (**argv == '-') {

      switch ((*argv)[1]) {
        case 'h':
          printHelp(prog_name);
          break;
        case 'f':
            checkfile = 1;
            break;
        default:
          fprintf(stdout, "%s: Invalid option %s. Use -h for help.\n",
                 prog_name, *argv);
      }
    } else {
      if (entryCount < LENGTH(entries)) {
        entries[entryCount].word = *argv;
        entries[entryCount++].counter = 0;
      }
    }
    argv++;
  }
  if (entryCount == 0) {
    fprintf(stdout, "%s: Please supply at least one word. Use -h for help.\n",
           prog_name);
    return EXIT_FAILURE;
  }
  if (entryCount == 1) {
    fprintf(stdout, "Looking for a single word\n");
  } else {
    fprintf(stdout, "Looking for %d words\n", entryCount);
  }

  process_stream(entries, entryCount);
  print_result(entries, entryCount);
  if (checkfile == 1) savefile_result(entries, entryCount);
  return EXIT_SUCCESS;
}
