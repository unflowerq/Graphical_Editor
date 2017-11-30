# algorithm_study2

그래픽 편집기(Graphical Editor)
 
그래픽 편집기를 만드는 규칙은 이러하다.
1. 입력은 한 줄에 하나씩의 편집기 명령으로 구성된다.
2. 각 명령은 줄 맨 앞에 있는 대문자 한개로 표현된다.
3. 매개변수가 필요한 경우에는 그 명령과 같은 줄에 스페이스로 분리되어 입력 한다.
4. 픽셀은 1 ~ M 열과, 1 ~ N 행 으로 표현된다.
5. 책에선 유효 범위를 250 픽셀 안쪽으로 정하지만 난 무시하겠다.(옆집 강아지의 이름을 기억해 주지 않아!)
6. 좌측 상단을 1, 1 으로 정하고, 이곳을 원점으로 정한다.
7. 6번에 의해 우측 방향, 하단 방향으로 픽셀이 길어 진다.
8. 흰색은 O, 빨간색은 R, 파란색은 B, 등으로 표기 한다.

문제
구현해야 하는 명령
명령 : 설명
I M N   : M X N 크기 만크 흰색으로 칠해진 이미지를 새로 만든다.
C       : 현재의 픽샐을 모두 흰색으로 칠한다.
L X Y C : X, Y 위치의 픽셀의 색을 C 색으로 칠한다.

V X Y1 Y2 C     : (X, Y1) ~ (X, Y2) 의 수직 방향을 C 색으로 칠한다.
H X1 X2 Y C     : (X1, Y) ~ (X2, Y) 의 수평 방향을 C 색으로 칠한다.
K X1 Y1 X2 Y2 C : 점(X1, Y1), 점(X2, Y2) 을 이용하여 사각형을 그리고 C 색으로 칠한다.

F X Y C : 점(X, Y)을 기준으로 C 색 페인트를 칠한다.
잠깐, 페인트는 그림판의 페인트 기능과 같다. 즉, 해당 점(A)의 색(C)을 기준으로 배경색이라 정한다. 이 배경색의 경계선색 안쪽으로 원하는 색을 칠한다. 여기서의 경계선색이란, 배경색과 다른 색을 뜻한다.

S Name : 현재의 이미지를 Name이라는 파일로 저장한다.
X      : 프로그램 끄기


구현해야 하는 사용자 인터페이스 
1. S 명령이 있을 때 마다, 파일을 만들고 화면에 출력한다.
2. 출력은 문자로 한다.
3. I C L V H K F S X 명령 외의 명령이 있으면 그 줄 전체를 무시하고, 다음 명령을 대기 한다.

input example
- I 5 6
- L 2 3 A
- S one.bmp
- G 2 3 J
- F 3 3 J
- V 2 3 4 W
- H 3 4 2 Z
- S two.bmp
- X

output example
- one.bmp
- OOOOO
- OOOOO
- OAOOO
- OOOOO
- OOOOO
- OOOOO
- two.bmp
- JJJJJ
- JJZZJ
- JWJJJ
- JWJJJ
- JJJJJ
- JJJJJ
