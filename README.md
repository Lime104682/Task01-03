# Task01-03
박인식 과제 제출 Repository

# TASK01_Vector - 질문 및 검색어
## 질문
안녕하세요.

보내주신 노션의 벡터 연산 페이지의 출력예시표에 있는 타켓 추적 테스트 부분에 대해 질문드릴 점이 있어 이렇게 메세지를 남깁니다.

우선 제가 공부한것이 부족하여 부족한 부분이 많고, 잘 못 이해하여 잘못된 접근법으로 접근했을 가능성이 높다는 점을 미리 말씀드립니다.

그럼에도 혹시나 하는 마음에 한 번만 확인해주시면 감사하겠습니다.

현재 출력예시표에는 대상 위치: (0,0,0)에 대한 방향 벡터가 (0,0,1), 방향 벡터 길이가 1, 거리 값이 0으로 되어있습니다.

제가 직접 TestTargetTracking()에서 생성된 obj객체의 값을 계산해본 결과 아래와 같았습니다.

position 값 : (0,0,0)

forward(Z축) 값 : (0,0,1)

right(X축) 값 : (-1,0,0)

up(Y축) 값 : (0,1,0)

여기서 방향 단위 벡터의 값은 힌트로 주신대로 GetDirectionToTarget(target)의 매개변수로 받아온 타겟 벡터 위치(targetPosition) - 생성된 obj객체의 위치(position)로 계산했습니다.
 
계산하면 targetPosition(0,0,0) - position(0,0,0) = (0-0, 0-0, 0-0)이므로 결과값은 (0,0,0)으로 반환되고 방향 벡터는 (0,0,0), 방향 벡터 길이도 0입니다만 출력예시표에는 (0,0,1)이라 표시되어 있으며 방향 벡터 길이 1이라고 표시되어 있습니다.

또한, 방향 단위 벡터가 (0,0,1)이라면, 두 위치 간 거리는 힌트로 주신 두 점 사이의 거리 공식에 의해 √((0−0)²+(0−0)²+(0−1)²) = 1이 되어야 할 것 같은데, 출력 예시표에서는 거리도 0으로 표기되어 있습니다. 

혹시 제가 잘못 이해하고 있거나, 놓친 부분이 있다면 알려주시면 더 공부해보도록 하겠습니다. 읽어주셔서 감사합니다.

## Main.cpp_Class Object 검색어
생성자
 * c++ 벡터의 Cross함수
 * https://m.blog.naver.com/junghs1040/222104997411
 * 벡터 내적 계산 : dot()
 * 벡터 외적 계산 : cross()
 * 아래 TestVectorOperations()의 TASK3참고
   
 * 벡터 정규화 이유
 * https://handhp1.tistory.com/8
 * 크기(길이)를 1로 고정화 시켜 두고 계산하기 위해
 * 방향이 같은 벡터들을 정규화하면 모두 같은 벡터가 된다.
 * 크기(길이)를 제외한 방향만 고려하고 싶을 때 사용
 * 벡터들을 계산할 때 벡터의 크기로 식의 결과를 왜곡시키지 않는다.
 * https://blog.naver.com/PostView.naver?blogId=edgerider&logNo=221296601764
 * 크기 = 길이
   
 * 게임 3d 벡터 좌표계
 * https://m.blog.naver.com/ideugu/221411002215
   
 * 손 좌표계 구분법
 * https://dev-igner.tistory.com/51
 * Y-UP 좌표계(엄지 X축, 검지 Y축, 중지 Z축) 기준 왼손과 오른손 좌표계는 Z축의 +방향이 정반대 방향이다.
   
 * 게임 좌표계 구분 이유
 * https://velog.io/@ounols/%EA%B2%8C%EC%9E%84-%EC%88%98%ED%95%99-1.-3%EC%B0%A8%EC%9B%90-%EA%B3%B5%EA%B0%84-%EB%A7%9B%EB%B3%B4%EA%B8%B0
 * https://hanseongbugi2study.tistory.com/177#%EC%99%BC%EC%86%90%20%EC%A2%8C%ED%91%9C%EA%B3%84-1
   
 * 벡터 계산기
 * https://mxncalc.com/ko/vectors-calculator
   
 * 3차원 그래프 그려주는 사이트
 * https://www.desmos.com/3d?lang=ko
 
 * 결론
   * Object 객체를 생성할 때 초기화 시킨다.
   * 생성된 객체(크기 == 1)의 중심점(position), 앞뒤(forward), 좌우(right), 상하(up)의 방향을 구한다.
   * 좌표계는 기본적으로 Y-UP 좌표계를 따른다.
   * 추가적으로 TestTargetTracking()의 obj객체 한정 ?손 좌표계로 추정(모르겠습니다....)(느낌상 왼손 좌표계일 거라 생각합니다.)
   *
   * 좌표계 이유
      1. 기본적으로 제시된 코드 중 worldUp 벡터의 y축이 1 이라고 명시되어 있어서 Y-UP이라 생각함
      2. TestTargetTracking()의 obj객체 한정 직접 계산한 결과 아래처럼 나옴
         * position 값 : (0,0,0)
         * forward(Z축) 값 : (0,0,1)
         * right(X축) 값 : (-1,0,0)
         * up(Y축) 값 : (0,1,0)

TASK 1
  * 방향 단위 벡터, 3차원 단위 벡터
  * https://m.blog.naver.com/galaxyenergy/222616653347
  * https://zzozzomin08.tistory.com/94
  * 예)
    * V1 = (1,1,1)의 방향 단위 벡터는 (1/루트3, 1/루트3, 1/루트3)
  * 수식
  * V1벡터스칼라값 = 루트 (V1.x)제곱 + (V1.y)제곱 + (V1.z)제곱
  * 단위 벡터(v) = (V1.x/V1벡터스칼라값, V1.y/V1벡터스칼라값, V1.z/V1벡터스칼라값)
  * 
  * 결론
    * 정규화는 단위 벡터화이다.
    * 정규화 즉 단위 벡터화 하면 크기(길이)를 1로 변하게 한다.
    * 방향의 범위는 각 벡터의 요소마다 -1(음수)(최소) ~ 1(양수)(최대)의 범위를 가진다.
  
TASK 2
  * 3차원 공간에서의 두 점 사이의 거리 공식
  * https://m.blog.naver.com/galaxyenergy/221263626715
  * cmath 헤더의 두 점 사이의 거리 함수
  * https://ks-factory.tistory.com/229
  * 거리 함수 sqrt()와 pow()
  * https://xzio.tistory.com/254
  
TASK 3
  * 벡터 외적으로 좌우구분
  * https://lalyns.tistory.com/entry/%EB%B2%A1%ED%84%B0-%EB%82%B4%EC%A0%81%EA%B3%BC-%EC%99%B8%EC%A0%81%EC%9D%84-%EC%9D%91%EC%9A%A9%ED%95%9C-%EC%99%BC%EC%AA%BD%EA%B3%BC-%EC%98%A4%EB%A5%B8%EC%AA%BD%EC%9D%98-%ED%8C%90%EB%B3%84
  * 특정 방향을 중심으로한 회전으로 알기 때문에 
  * 예)
    * x축 방향을 중심으로 회전하면 위/아래를 구분가능
  
TASK 4
  * 3차원 벡터 시야각 계산
  * https://lalyns.tistory.com/entry/%EB%82%B4%EC%A0%81%EC%9D%84-%EC%82%AC%EC%9A%A9%ED%95%9C-%EC%8B%9C%EC%95%BC-%ED%8C%90%EB%B3%84


## Main.cpp_TestVectorOperations() 검색어
TASK 2
  * 벡터 스칼라 곱
  * https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sallygarden_ee&logNo=221265467087

## Vector.hpp 검색어
 * c++ 벡터 Dot, Cross, 3차원 벡터 외적 공식
 * https://rhksgml78.tistory.com/124
 * 
 * inline 함수

  
# TASK02_Pooling - 설명 및 검색어
## 설명
 * Assets의 Scenes의 Task02_Pooling 씬 선택하시면 됩니다.
 * 실행하시고 하얀색 바닥을 마우스로 클릭하시면 좌우에 대응하게 움직입니다.
     
## 검색어
 * 오브젝트 풀링
 * https://youtu.be/JxP-kqstMAY?si=WC9Y_MHl8eHbajSq
 * 
 * 유니티 마우스 이동
 * https://www.ibatstudio.com/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EB%A7%88%EC%9A%B0%EC%8A%A4-%ED%81%B4%EB%A6%AD-%EC%9D%B4%EB%8F%99-%EB%B0%8F-    %ED%9A%8C%EC%A0%84-%EB%B0%A9%EB%B2%95/
 *
 * ObjectPool<EnemyPool>()
 * 유니티 공식 오브젝트풀링

# TASK03_Parsing - 검색어   
## 검색어
 * json 유니티
 * https://www.youtube.com/watch?v=fHXN1DJKDk0&t=934s
 * https://www.youtube.com/watch?v=N9r2ju3xJGk&t=823s
    * [System.Serializable]
        * 직렬화 하기 위한 코드  
    * JsonUtility.FromJsonOverwrite()
        * https://docs.unity3d.com/6000.1/Documentation/ScriptReference/JsonUtility.FromJsonOverwrite.html
        * 기존 객체에 JSON 데이터를 로드
    * Application.datapath
        * https://geukggom.tistory.com/9
        * https://3dmpengines.tistory.com/1745
        * 해당 프로젝트 Assets 파일
 *  
 * 유니티 엑셀 파일 json 저장 불러오기
 * https://bonnate.tistory.com/355
 * 
 * 유니티 csv 파일 읽기
 * https://dongsik-blog.tistory.com/101
 * https://yoonstone-games.tistory.com/14#google_vignette
 * https://yundongdong.tistory.com/4
 * https://velog.io/@dbdnjstkd369/%EC%9C%A0%EB%8B%88%ED%8B%B0%EC%97%90%EC%84%9C-CSV%EB%A5%BC-Scriptable-Object%EB%A1%9C-%EB%A7%8C%EB%93%A4%EC%96%B4%EC%A3%BC%EA%B8%B0
 * 
 * 유니티 Json 파일 저장 예쁘게 하는법
 * https://gall.dcinside.com/mgallery/board/view/?id=game_dev&no=32498

 * 기타 검색어
  * 유니티 json파일 위치
  * 유니티 json list 저장
  * 유니티 json 파싱
  * json 파싱
  * 유니티 Json 파일 읽기
  * 엑셀 json 변환 사이트 
  * 유니티 csv 데이터가 Json에 안들어가짐 
