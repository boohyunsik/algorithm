import java.util.*;
class Solution {
    static public class Descending implements Comparator<Integer> {
        @Override
        public int compare(Integer o1, Integer o2) {
            return o2.compareTo(o1);
        }
    }

    static public class SongDescending implements Comparator<Song> {
        @Override
        public int compare(Song o1, Song o2) {
            Integer p1 = o1.play;
            Integer p2 = o2.play;
            return p2.compareTo(p1);
        }
    }

    static public class GpDescending implements Comparator<GenreAndPlay> {
        @Override
        public int compare(GenreAndPlay o1, GenreAndPlay o2) {
            Integer p1 = o1.play;
            Integer p2 = o2.play;
            return p2.compareTo(p1);
        }
    }

    static public class Song {
        Integer play;
        int index;

        Song(int index, Integer play) {
            this.play = play;
            this.index = index;
        }
    }

    static public class GenreAndPlay {
        String genre;
        int play;
        GenreAndPlay(String g, int p) {
            genre = g;
            play = p;
        }
    }

    static public int[] solution(String[] genres, int[] plays) {
        HashMap<String, ArrayList<Song>> map = new HashMap();
        HashMap<String, Integer> playMap = new HashMap();


        for (int i=0; i<plays.length; i++) {
            String genre = genres[i];
            if (map.containsKey(genre)) {
                map.get(genre).add(new Song(i, plays[i]));
                playMap.put(genre, playMap.get(genre) + plays[i]);
            } else {
                ArrayList<Song> list = new ArrayList();
                list.add(new Song(i, plays[i]));
                map.put(genre, list);
                playMap.put(genre, plays[i]);
            }
        }
        for (String key : map.keySet()) {
            map.get(key).sort(new SongDescending());
        }

        ArrayList<GenreAndPlay> sortedPlayList = new ArrayList();
        for (String key : playMap.keySet()) {
            GenreAndPlay newgp = new GenreAndPlay(key, playMap.get(key));
            sortedPlayList.add(newgp);
        }
        sortedPlayList.sort(new GpDescending());

        ArrayList<Integer> answerList = new ArrayList();
        for (GenreAndPlay gp : sortedPlayList) {
            String key = gp.genre;
            if (map.get(key).size() == 1) {
                answerList.add(map.get(key).get(0).index);
            } else {
                answerList.add(map.get(key).get(0).index);
                answerList.add(map.get(key).get(1).index);
            }
        }

        int[] answer = new int[answerList.size()];
        int idx = 0;
        for (Integer e : answerList) {
            answer[idx++] = e;
        }

        return answer;
    }
}
