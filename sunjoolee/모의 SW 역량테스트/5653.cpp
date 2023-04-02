#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int OFFSET = 325;

int dirR[4] = { 0, 0, 1, -1 };
int dirC[4] = { 1, -1, 0, 0 };

//줄기 세포
struct Cell {
	pair<int, int> pos;
	int lifeSpan;

	//생성자
	Cell(pair<int, int> _pos, int _lifeSpan) : pos(_pos), lifeSpan(_lifeSpan) {};
};

//줄기 세포를 담은 벡터 내림차순으로 정렬
//0일 때 pop_back()하기 위함
bool cmp(pair<int, Cell> a, pair<int, Cell> b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {

		//줄기세포가 위치한 칸이면 1, 빈 칸이면 0
		bool board[700][700] = { 0 };

		//<활성화될 때까지 남은 시간, 줄기 세포>
		vector < pair<int, Cell>> notActivated;
		//<죽을 때까지 남은 시간, 줄기 세포>
		vector < pair<int, Cell>> activated;

		int N, M, K;
		cin >> N >> M >> K;

		//초기 상태 입력받기
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int X;
				cin >> X;
				if (X == 0) continue;

				Cell cell({ i, j }, X);

				notActivated.push_back({ X, cell });
				board[i + OFFSET][j + OFFSET] = 1;
			}
		}
		sort(notActivated.begin(), notActivated.end(), cmp);

		//상하좌우로 분열하는 줄기 세표
		//시간 단축 - 한 번 분열한 세포는 다시 분열 처리 할 필요 X!!
		vector<Cell> growingCells;

		//K시간동안 배양하기
		while (K--) {
			//1-1. 줄기 세포 상하좌우로 분열하기

			//보드에 새로 추가될 줄기 세포 정보 
			// cellsToAdd[칸 좌표] = 해당 칸에 추가될 줄기 세포의 수명
			map<pair<int, int>, int> newCells;

			for (int i = 0; i < growingCells.size(); ++i) {
				Cell curCell = growingCells[i];

				pair<int, int> nextPos;
				for (int d = 0; d < 4; ++d) {
					nextPos.first = curCell.pos.first + dirR[d];
					nextPos.second = curCell.pos.second + dirC[d];

					//비어있는 칸으로만 분열 가능
					if (board[nextPos.first + OFFSET][nextPos.second + OFFSET]) continue;

					//보드에 새로 추가해야할 목록에 같은 위치로 분열 할 세포 있는지 확인
					if (newCells.find(nextPos) == newCells.end()) {
						newCells[nextPos] = curCell.lifeSpan;
					}
					else {
						newCells[nextPos] = max(newCells[nextPos], curCell.lifeSpan);
					}
				}
			}
			growingCells.clear();

			//2-1. 활성 상태에 있는 줄기 세포: 죽을 때까지 남은 시간 -= 1
			for (int i = 0; i < activated.size(); ++i) {
				activated[i].first -= 1;
			}
			//2-2. 비활성 상태에 있는 줄기 세포: 활성화될 때까지 남은 시간 -= 1
			for (int i = 0; i < notActivated.size(); ++i) {
				notActivated[i].first -= 1;
			}
			sort(activated.begin(), activated.end(), cmp);
			sort(notActivated.begin(), notActivated.end(), cmp);

			//2-3. 죽을 때까지 남은 시간 0 처리
			while (!activated.empty()) {
				if (activated.back().first > 0) break;
				activated.pop_back();
			}
			//2-4. 활성화될 때까지 남은 시간 0 처리
			while (!notActivated.empty()) {
				if (notActivated.back().first > 0) break;
				activated.push_back({ notActivated.back().second.lifeSpan, notActivated.back().second });
				growingCells.push_back(notActivated.back().second);
				notActivated.pop_back();
			}

			//1-2. 추가된 줄기 세포 보드에 추가

			//map iterator로 순회할 때
			//iterator->first: key 값
			//iterator->second: value 값 
			for (auto it = newCells.begin(); it != newCells.end(); ++it) {
				Cell newCell(it->first, it->second);
				notActivated.push_back({ newCell.lifeSpan, newCell });
				board[newCell.pos.first + OFFSET][newCell.pos.second + OFFSET] = 1;
			}
		}

		int cnt = activated.size() + notActivated.size();
		cout << "#" << t << " " << cnt << "\n";
	}

	return 0;
}
