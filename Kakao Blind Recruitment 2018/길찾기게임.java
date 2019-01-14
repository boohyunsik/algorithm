import java.util.ArrayList;
import java.util.Comparator;

class Solution {
    static Node root;
    static boolean visit[] = new boolean[10001];
    static int idx = 0;
    static int[] preArray;
    static int[] postArray;
    static class Pos {
        int x, y, index;
        Pos(int x, int y, int index) {
            this.x = x;
            this.y = y;
            this.index = index;
        }
    }

    static class comparator implements Comparator<Pos> {
        @Override
        public int compare(Pos o1, Pos o2) {
            if (o1.y < o2.y) {
                return 1;
            } else if (o1.y == o2.y) {
                if (o1.x > o2.x) {
                    return 1;
                } else if (o1.x == o2.x) {
                    return 0;
                }
            }
            return -1;
        }
    }

    static class Node {
        int index, x, y;
        Node left = null, right = null;
        Node(int index, int x, int y) {
            this.index = index;
            this.x = x;
            this.y = y;
        }
    }

    static void preorder(Node node) {
        if (node != null) {
            if (!visit[node.index]) {
                preArray[idx++]  = node.index;
                visit[node.index] = true;
            }
            preorder(node.left);
            preorder(node.right);
        }
    }

    static void postorder(Node node) {
        if (node != null) {
            postorder(node.left);
            postorder(node.right);
            if (!visit[node.index]) {
                postArray[idx++] = node.index;
                visit[node.index] = true;
            }
        }
    }


    public static int[][] solution(int[][] nodeinfo) {
        ArrayList<Pos> list = new ArrayList();
        for (int i=0; i<nodeinfo.length; i++) {
            Pos pos = new Pos(nodeinfo[i][0], nodeinfo[i][1], i + 1);
            list.add(pos);
        }
        list.sort(new comparator());

        root = new Node(list.get(0).index, list.get(0).x, list.get(0).y);
        for (int i=0; i<list.size(); i++) {
            Pos pos = list.get(i);
            Node node = root;
            while (true) {
                if (pos.x < node.x) {
                    // to the left
                    if (node.left != null) {
                        node = node.left;
                        continue;
                    } else {
                        node.left = new Node(pos.index, pos.x, pos.y);
                        break;
                    }
                } else {
                    // to the right
                    if (node.right != null) {
                        node = node.right;
                        continue;
                    } else {
                        node.right = new Node(pos.index, pos.x, pos.y);
                        break;
                    }
                }
            }
        }

        postArray = new int[list.size()];
        preArray = new int[list.size()];
        preorder(root);
        for (int i=0;i<10001;i++) {
            visit[i] = false;
        }
        idx = 0;
        postorder(root);
        int[][] result = new int[2][];
        result[0] = preArray;
        result[1] = postArray;
        return result;
    }
}
