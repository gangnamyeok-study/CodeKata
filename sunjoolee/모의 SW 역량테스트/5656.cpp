#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX_W = 12 + 1;
const int MAX_H = 15 + 1;

int N, W, H;

int board[MAX_H][MAX_W];
int boardSave[MAX_H][MAX_W]; //보드 원상복구를 위한 저장용 보드

//구슬 떨어트릴 수 있는 모든 경우의 수 계산
vector<vector<int>> getAllOrders() {
	vector<vector<int>> allOrders;
	vector<int> tmpOrder;

	for (int i = 0; i < W; ++i) {
		tmpOrder.push_back(i);
		if (N == 1) {
			allOrders.push_back(tmpOrder);
			tmpOrder.pop_back();
			continue;
		}
		for (int j = 0; j < W; ++j) {
			tmpOrder.push_back(j);
			if (N == 2) {
				allOrders.push_back(tmpOrder);
				tmpOrder.pop_back();
				continue;
			}
			for (int k = 0; k < W; ++k) {
				tmpOrder.push_back(k);
				if (N == 3) {
					allOrders.push_back(tmpOrder);
					tmpOrder.pop_back();
					continue;
				}
				for (int l = 0; l < W; ++l) {
					tmpOrder.push_back(l);
					allOrders.push_back(tmpOrder);
					tmpOrder.pop_back();
				}
				tmpOrder.pop_back();
			}
			tmpOrder.pop_back();
		}
		tmpOrder.pop_back();
	}

	/*
	cout << "\n--------allOrders----------\n";
	for (int i = 0; i < allOrders.size(); ++i) {
		for (int j = 0; j < allOrders[i].size(); ++j){
			cout << allOrders[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n---------------------------\n";
	*/

	return allOrders;
}

//벽돌이 제거되고 난 후 빈 칸 없애기
void arrangeBoard() {
	/*
	cout << "\n--------before arrange board-----------\n";
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			cout << board[h][w] << " ";
		}
		cout << "\n";
	}
	*/

	//w열에 있는 벽돌들의 정보(숫자)정보 저장
	queue<int> brick_nums;
	for (int w = 0; w < W; ++w) {
		for (int h = H-1; h >= 0; --h) {
			if (board[h][w] != 0) {
				brick_nums.push(board[h][w]);
				board[h][w] = 0;
			}
		}

		//벽돌 정보 보드 아래에서부터 다시 채우기
		for (int h = H - 1; h >= 0; --h) {
			if (!brick_nums.empty()) {
				board[h][w] = brick_nums.front();
				brick_nums.pop();
			}
			else break;
		}
	}

	/*
	cout << "\n--------after arrange board-----------\n";
	for (int h = 0; h < H; ++h) {
		for (int w = 0; w < W; ++w) {
			cout << board[h][w] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
}

bool inRange(int cur_h, int cur_w) {
	if (cur_h < 0 || cur_h >= H) return false;
	if (cur_w < 0 || cur_w >= W) return false;
	return true;
}

//구슬 떨어트리기
//order: 구슬이 떨어질 위치
void fall(vector<int> order) {
	for (int i = 0; i < order.size(); ++i) {
		//현재 구슬이 떨어져 부딪힐 벽돌의 좌표 구하기
		int cur_w = order[i];
		int cur_h = -1; //no value

		for (int h = 0; h < H; ++h) {
			if (board[h][cur_w] != 0) {
				cur_h = h;
				break;
			}
		}
		//현재 구슬이 떨어질 위치 아래 아무 벽돌도 없는 경우
		if (cur_h == -1) continue;

		//현재 구슬이 떨어져 제거될 벽돌들의 좌표
		queue<pair<int, int>> bricks;
		bricks.push({ cur_h, cur_w });

		//중복된 좌표가 큐에 들어가는 것을 방지하기 위한 집합
		set<pair<int, int>> inQueue;
		inQueue.insert({ cur_h, cur_w });

		while (!bricks.empty()) {
			//현재 보드에 남은 벽돌의 수 구하기
			int remainCnt = 0;
			for (int h = 0; h < H; ++h) {
				for (int w = 0; w < W; ++w) {
					if (board[h][w] != 0) remainCnt++;
				}
			}
			if (remainCnt == 0)return;
			
			int brick_h = bricks.front().first;
			int brick_w = bricks.front().second;
			bricks.pop();

			int brick_num = board[brick_h][brick_w];
			if (brick_num == 0) continue; //이미 제거된 벽돌
			board[brick_h][brick_w] = 0; ////현재 벽돌 제거
			
			//벽돌 숫자 1인 경우 종료
			if (brick_num == 1) continue;
			
			//벽돌 숫자 1보다 큰 경우 폭발하는 범위 내 벽돌들의 좌표 구하기
			for (int range = 1; range < brick_num; ++range) {
				int nextBrick_h; 
				int nextBrick_w;
				//상
				nextBrick_h = brick_h + range;
				nextBrick_w = brick_w;
				if (inRange(nextBrick_h, nextBrick_w) && (board[nextBrick_h][nextBrick_w] != 0) && (inQueue.find({nextBrick_h, nextBrick_w}) == inQueue.end())) {
					bricks.push({ nextBrick_h, nextBrick_w });
					inQueue.insert({ nextBrick_h, nextBrick_w });
				}
				//하
				nextBrick_h = brick_h - range;
				nextBrick_w = brick_w;
				if (inRange(nextBrick_h, nextBrick_w) && (board[nextBrick_h][nextBrick_w] != 0) && (inQueue.find({ nextBrick_h, nextBrick_w }) == inQueue.end())) {
					bricks.push({ nextBrick_h, nextBrick_w });
					inQueue.insert({ nextBrick_h, nextBrick_w });
				}
				//좌
				nextBrick_h = brick_h;
				nextBrick_w = brick_w - range;
				if (inRange(nextBrick_h, nextBrick_w) && (board[nextBrick_h][nextBrick_w] != 0) && (inQueue.find({ nextBrick_h, nextBrick_w }) == inQueue.end())) {
					bricks.push({ nextBrick_h, nextBrick_w });
					inQueue.insert({ nextBrick_h, nextBrick_w });
				}
				//우
				nextBrick_h = brick_h;
				nextBrick_w = brick_w + range;
				if (inRange(nextBrick_h, nextBrick_w) && (board[nextBrick_h][nextBrick_w] != 0) && (inQueue.find({ nextBrick_h, nextBrick_w }) == inQueue.end())) {
					bricks.push({ nextBrick_h, nextBrick_w });
					inQueue.insert({ nextBrick_h, nextBrick_w });
				}
			}
		}
		//구슬 떨어지고 제거될 벽돌들이 모두 제거된 후 보드 재정렬
		arrangeBoard();
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for(int t = 1; t<= T; ++t){
		for (int h = 0; h < MAX_H; ++h) {
			for (int w = 0; w < MAX_W; ++w) {
				board[h][w] = 0;
				boardSave[h][w] = 0;
			}
		}

		//전역변수 초기화
		cin >> N >> W >> H;

		int input;
		for (int h = 0; h < H; ++h) {
			for (int w = 0; w < W; ++w) {
				cin >> input;
				board[h][w] = input; 
				boardSave[h][w] = input;
			}
		}
		
		//보드에 구슬을 떨어트릴 수 있는 모든 경우
		vector<vector<int>> allOrders = getAllOrders();

		//보드에 구슬을 모든 경우에 따라 떨어트림
		//벽돌을 최대한 많이 제거하려고 할 때 남은 벽돌의 개수
		int minCnt = H*W;
		for (int i = 0; i < allOrders.size(); ++i) {
			fall(allOrders[i]);
		
			//구슬을 떨어트린 후 벽돌의 수 구하기
			int remainCnt = 0;
			for (int h = 0; h < H; ++h) {
				for (int w = 0; w < W; ++w) {
					if(board[h][w] != 0) remainCnt++;

					//보드 원상복구
					board[h][w] = boardSave[h][w];
				}
			}
			minCnt = min(minCnt, remainCnt);
			if (minCnt == 0) break;
		}
		cout <<"#"<<t<<" "<<minCnt<<"\n";
	}


	return 0;
}
