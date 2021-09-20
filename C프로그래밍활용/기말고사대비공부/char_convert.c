#INCLUDE<STDIO.H>

INT MAIN(VOID)
{
	FILE* FP1, * FP2;
	INT C;

	FP1 = FOPEN("21I.C", "R");
	IF (FP1 == NULL)
	{
		PRINTF("ERROR\N");
		RETURN 1;
	}
	FP2 = FOPEN("CHAR_CONVERT.C", "W");
	IF (FP2 == NULL)
	{
		PRINTF("ERROR\N");
	}

	WHILE ((C = FGETC(FP1)) != EOF)
	{
		IF ('A' <= C && C <= 'Z')
		{
			C = C - 32;
		}
		FPUTC(C, FP2);
	}
	FCLOSE(FP1);
	FCLOSE(FP2);
	PRINTF("SUCCESS\N");
}
//20191205