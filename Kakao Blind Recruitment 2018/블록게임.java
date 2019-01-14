import java.util.ArrayList;
class Solution {
    static class Pos {
        int r, c;
        Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    static class Block {
        ArrayList<Pos> posList = new ArrayList();
        ArrayList<Pos> blockList = new ArrayList();
        boolean isDestroyed = false;
    }

    static Block[] blockArr = new Block[201];

    public static int solution(int[][] board) {
        int answer = 0;
        int nBlock = 0;
        for (int r=0;r<board.length;r++) {
            for (int c=0;c<board[r].length; c++) {
                if (board[r][c] != 0 && blockArr[board[r][c]] == null) {
                    Block newBlock = new Block();
                    int blockVal = board[r][c];
                    if (c + 2 < board[0].length && blockVal == board[r][c+1] && blockVal == board[r][c+2]) {
                        newBlock.blockList.add(new Pos(r, c));
                        newBlock.blockList.add(new Pos(r, c + 1));
                        newBlock.blockList.add(new Pos(r, c + 2));
                        // 가로
                        if (r-1 >= 0 && (board[r-1][c] == blockVal || board[r-1][c + 1] == blockVal || board[r-1][c + 2] == blockVal)) {
                            // 위로 볼록
                            if (board[r-1][c] != blockVal)newBlock.posList.add(new Pos(r - 1, c));
                            else newBlock.blockList.add(new Pos(r - 1, c));

                            if (board[r-1][c+1] != blockVal)newBlock.posList.add(new Pos(r - 1, c + 1));
                            else newBlock.blockList.add(new Pos(r - 1, c + 1));

                            if (board[r-1][c+2] != blockVal)newBlock.posList.add(new Pos(r - 1, c + 2));
                            else newBlock.blockList.add(new Pos(r - 1, c + 2));
                        } else if (r+1 < board.length && (board[r+1][c] == blockVal || board[r+1][c + 1] == blockVal || board[r+1][c + 2] == blockVal)){
                            // 아래로 볼록
                            if (board[r+1][c] != blockVal)newBlock.posList.add(new Pos(r + 1, c));
                            else newBlock.blockList.add(new Pos(r + 1, c));

                            if (board[r+1][c+1] != blockVal)newBlock.posList.add(new Pos(r + 1, c + 1));
                            else newBlock.blockList.add(new Pos(r + 1, c + 1));

                            if (board[r+1][c+2] != blockVal)newBlock.posList.add(new Pos(r + 1, c + 2));
                            else newBlock.blockList.add(new Pos(r + 1, c + 2));
                        }
                    }

                    if (r + 2 < board.length && blockVal == board[r + 1][c] && blockVal == board[r + 2][c]) {
                        // 세로
                        newBlock.blockList.add(new Pos(r, c));
                        newBlock.blockList.add(new Pos(r + 1, c));
                        newBlock.blockList.add(new Pos(r + 2, c));
                        if (c + 1 < board[0].length && (board[r][c+1] == blockVal || board[r+1][c+1] == blockVal || board[r+2][c+1] == blockVal)) {
                            // 우로 볼록
                            if (board[r][c + 1] != blockVal)newBlock.posList.add(new Pos(r, c + 1));
                            else newBlock.blockList.add(new Pos(r, c + 1));

                            if (board[r + 1][c + 1] != blockVal)newBlock.posList.add(new Pos(r + 1, c + 1));
                            else newBlock.blockList.add(new Pos(r + 1, c + 1));

                            if (board[r + 2][c + 1] != blockVal)newBlock.posList.add(new Pos(r + 2, c + 1));
                            else newBlock.blockList.add(new Pos(r + 2, c + 1));
                        } else if (c - 1 >= 0 && (board[r][c - 1] == blockVal || board[r + 1][c - 1] == blockVal || board[r + 2][c - 1] == blockVal)){
                            // 좌로 볼록
                            if (board[r][c - 1] != blockVal)newBlock.posList.add(new Pos(r, c - 1));
                            else newBlock.blockList.add(new Pos(r, c - 1));

                            if (board[r + 1][c - 1] != blockVal)newBlock.posList.add(new Pos(r + 1, c - 1));
                            else newBlock.blockList.add(new Pos(r + 1, c - 1));

                            if (board[r + 2][c - 1] != blockVal)newBlock.posList.add(new Pos(r + 2, c - 1));
                            else newBlock.blockList.add(new Pos(r + 2, c - 1));
                        }
                    }

                    if (newBlock.posList.size() == 2 && newBlock.blockList.size() == 4) {
                        blockArr[blockVal] = newBlock;
                        if (nBlock < blockVal) {
                            nBlock = blockVal;
                        }
                    }
                }
            }
        }
        while (true) {
            int count = 0;
            for (int i=0; i<= nBlock; i++) {
                if (blockArr[i] == null || blockArr[i].isDestroyed) {
                    continue;
                }
                int val = 0;
                for (int j=0; j<blockArr[i].posList.size(); j++) {
                    val += board[blockArr[i].posList.get(j).r][blockArr[i].posList.get(j).c];
                }

                if (val == 0) {
                    int cnt2 = 0;
                    for (int j=0; j<blockArr[i].posList.size(); j++) {
                        int r = blockArr[i].posList.get(j).r;
                        int c = blockArr[i].posList.get(j).c;
                        while(r >= 0) {
                            if (board[r][c] != 0) {
                                break;
                            }
                            r--;
                            if (r == -1) {
                                cnt2++;
                            }
                        }
                    }
                    if (cnt2 == 2) {
                        count++;
                        for (int j=0; j<blockArr[i].blockList.size(); j++) {
                            board[blockArr[i].blockList.get(j).r][blockArr[i].blockList.get(j).c] = 0;
                        }
                        blockArr[i].isDestroyed = true;
                    }
                }
            }

            if (count == 0) {
                break;
            } else {
                answer += count;
            }
        }
        return answer;
    }
}
