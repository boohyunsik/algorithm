class Solution {
      static class Log {
        long start, end;
        Log (long s, long e) {
            start = s;
            end = e;
        }
    }

    public static Log convert(String time) {
        SimpleDateFormat spm = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
        try {
            String substr = time.substring(0, 19);
            Date date = spm.parse(substr);
            long end = date.getTime();

            substr = time.substring(20, 23);
            long digit = 100;
            for (int i=0; i<substr.length(); i++) {
                end += (substr.charAt(i) - '0') * digit;
                digit /= 10;
            }

            long duration = 0;
            digit = 1000;
            for (int i = 24; i< time.length(); i++) {
                char c = time.charAt(i);
                if (c >= '0' && c <= '9') {
                    duration += ((c-'0') * digit);
                    digit /= 10;
                }
            }
            long start = end - duration;
            return new Log(start + 1, end);

        } catch (ParseException e) {

        }
        return null;
    }

    public static int solution(String[] lines) {
        int answer = 0;
        ArrayList<Log> timeList = new ArrayList();
        for (int i=0; i<lines.length; i++) {
            timeList.add(convert(lines[i]));
        }

        for (int i=0; i<timeList.size(); i++) {
            int temp = 1;
            long startTime = timeList.get(i).end;
            long endTime = startTime + 999;

            for (int j=i+1; j<timeList.size(); j++) {
                if ((timeList.get(j).start >= startTime && timeList.get(j).start <= endTime) ||
                        (timeList.get(j).end >= startTime && timeList.get(j).end <= endTime) ||
                        (timeList.get(j).start <= startTime && timeList.get(j).end >= endTime)) {
                    temp++;
                } else {
                break;
            }
            }

            if (answer < temp) {
                answer = temp;
            }
        }
        return answer;
    }
}
