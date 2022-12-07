#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;

	//name의 길이
	int nameLen = name.length();

	//조이스틱 위, 아래 조작 최소 횟수
	int updown = 0;

	for (int i = 0; i < nameLen; ++i) {
		//조이스틱 위로 움직여야하는 횟수
		int up = int(name[i]) - int('A');
		//조이스틱 아래로 움직여야하는 횟수
		int down = 26 - up;

		updown += min(up, down);
	}

	//조이스틱 좌,우 조작 최소 횟수
	int leftright = name.length() - 1;

	//name과의 비교를 위한 A로만 이루어진 문자열
	string AAA = "";
	for (int i = 0; i < nameLen; ++i) {
		AAA += "A";
	}

	for (int i = 0; i < nameLen; ++i) {
		string tmpName = name;

		int case1 = 0;
		//0 ~ i까지 오른쪽으로 이동
		//커서 첫번째 알파벳에서 시작
		tmpName[0] = 'A';
		if (tmpName != AAA) {
			for (int j = 1; j <= i; ++j) {
				case1++;
				tmpName[j] = 'A';
				if (tmpName == AAA) break;
			}
		}
		//원점으로 복귀
		if (tmpName != AAA) case1 *= 2;
		//nameLen-1 ~ i+1까지 왼쪽으로 이동
		if (tmpName != AAA) {
			for (int j = nameLen-1; j > i; --j) {
				case1++;
				tmpName[j] = 'A';
				if (tmpName == AAA) break;
			}
		}
		
		//tmpName 초기화
		tmpName = name;
		
		int case2 = 0;
		//nameLen-1 ~ i+1까지 왼쪽으로 이동
		//커서 첫번째 알파벳에서 시작
		tmpName[0] = 'A';
		if (tmpName != AAA) {
			for (int j = nameLen - 1; j > i; --j) {
				case2++;
				tmpName[j] = 'A';
				if (tmpName == AAA) break;
			}
		}
		//원점으로 복귀
		if (tmpName != AAA) case2 *= 2;
		//0 ~ i까지 오른쪽으로 이동
		if (tmpName != AAA) {
			for (int j = 1; j <= i; ++j) {
				case2++;
				tmpName[j] = 'A';
				if (tmpName == AAA) break;
			}
		}
		
		leftright = min(leftright,min(case1, case2));
	}

	return answer = updown + leftright;
}

int main() {
	solution("JAN");
}
