"""
아래의 실행 결과가 나오도록 코드를 완성하시오.


Which one is correct team name in NBA?

0. New York Bulls
1. Los Angeles Kings
2. Golden State Warriors
3. Huston Rocket

answer Huston Rocket
"""

import json
with open("data/p01_questions_and_answers.json", "r", encoding="utf8") as f:
    contents = f.read()
    json_ex = json.loads(contents)

# 다음 출력 결과를 사례를 참고하여 작성하기 바랍니다.
print(json_ex['quiz']['sport']["q1"]["answer"])
print(json_ex['quiz']['sport']["q1"]["options"])


"""

print(json_ex______???____________ + "\n")
#print(json_ex["quiz"]["sport"])


options = json_ex______???____________
for i in range(len(options)):
    print(str(i) + ". " + options[i])

print("\n answer " + json_ex______???____________)
"""

