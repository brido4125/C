# 배열
- ```int aList[5]``` : 자료형 : **int[5]**, aList라는 변수명은 식별자 
- 배열의 이름은 그자체로 주소를 나타냄
- aList라는 주소를 담기 위한 그릇 : 포인터
- `int *pData = aList`처럼 주소를 담을 수 있음
- "Hello" => char[6] 짜리 배열
- 문자열 -> 가변길이 성질 가짐 but 배열은 고정 길이
- 항상 overflow에 대한 신경을 써줘야함
- `char szBuffler[8];` -> hello 라는 스트링 넣으면 공간 남음
- char aList[3][4]인 배열에 aList[0][4] 접근 하면 aList[1][0]에 접근하게 됨