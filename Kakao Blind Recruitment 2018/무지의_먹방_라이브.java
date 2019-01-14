import java.util.ArrayList;
import java.util.PriorityQueue;
class Solution {
    static class Data implements Comparable<Data>{
        int remain;
        Data(int remain) {
            this.remain = remain;
        }

        @Override
        public int compareTo(Data target) {
            if (remain > target.remain) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }

    public static int solution(int[] food_times, long k) {
        PriorityQueue<Data> minHeap = new PriorityQueue();
        int max = -1;
        for (int i=0; i<food_times.length; i++) {
            if (food_times[i] > max) {
                max = food_times[i];
            }
            minHeap.offer(new Data(food_times[i]));
        }

        long cnt = 0;
        long prev = 0;
        int nFood = food_times.length;
        while (cnt <= k) {
            if (minHeap.isEmpty()) {
                return -1;
            }
            Data data = minHeap.poll();
            if ( prev != 0 && prev == data.remain) {
                nFood--;
                continue;
            }
            cnt += (data.remain - prev) * (nFood);
            nFood--;
            prev = data.remain;
        }

        int index = food_times.length - 1;
        while (cnt != k) {
            if (food_times[index] >= prev) {
                cnt--;
            }
            index--;
            if (index < 0) {
                index = food_times.length - 1;
            }
        }
        if (index + 2 > food_times.length) {
            return 1;
        } else {
            return index + 2;
        }
    }
}
