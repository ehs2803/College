import json

with open("data/json_example.json", "r", encoding="utf8") as f:
    contents = f.read()                     # 파일 내용 읽어 오기
    print(type(contents), contents)
    json_data = json.loads(contents)        # json 파싱
    print('type(json_data)=', type(json_data))
    print(json_data["employees"])           # 딕셔너리처럼 사용하기
