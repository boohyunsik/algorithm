import java.util.ArrayList;
import java.util.Comparator;

public class Solution {

    static int[] nSolve;
    static int[] nChallenge;
    static double[] rate;

    static class Comparator implements java.util.Comparator<Data> {
        @Override
        public int compare(Data o1, Data o2) {
            if (o1.failRate < o2.failRate) {
                return 1;
            } else if (o1.failRate == o2.failRate) {
                if (o1.index > o2.index) {
                    return 1;
                }
            }
            return -1;
        }
    }

    static class Data {
        int index;
        double failRate;
        Data(int index, double failRate) {
            this.index = index;
            this.failRate = failRate;
        }
    }

    public static int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        nSolve = new int[N + 2];
        nChallenge = new int[N + 2];
        rate = new double[N + 2];

        for (int i = 0; i<=N; i++) {
            nSolve[i] = 0;
            nChallenge[i] = 0;
        }

        for (int i = 0; i<stages.length; i++) {
            int k = stages[i];
            for (int j = 1; j <= k; j++) {
                nChallenge[j]++;
                if (j < k) {
                    nSolve[j]++;
                }
            }
        }

        ArrayList<Data> list = new ArrayList();
        for (int i = 1; i < N + 1; i++) {
            rate[i] = 1.0 - (double)nSolve[i] / (double)nChallenge[i];
            if (nChallenge[i] == 0) {
                rate[i] = 0.0;
            }
            list.add(new Data(i, rate[i]));
        }
        list.sort(new Comparator());

        for (int i=0; i<list.size(); i++) {
            System.out.println(list.get(i).index + ", " + list.get(i).failRate);
            answer[i] = list.get(i).index;
        }
        return answer;
    }

    public static void main(String[] args) {
        solution(5, new int[]{2, 1, 2, 4, 2, 4, 3, 3});
    }

}
