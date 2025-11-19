import java.util.*;

// c++ for some reason handles utf strings non-natively, so this is in java


public class EasyAsCAB {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.nextLine());
        String[] s = new String[n];
        for(int i = 0; i < n; i++) {
            s[i] = scan.nextLine();
        }
        Set<Character> chars = new HashSet();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < s[i].length(); j++) {
                chars.add(s[i].charAt(j));
            }
        }
        Map<Character, Set<Character>> adj = new HashMap<>();
        Map<Character, Integer> deg = new HashMap<>();
        for(char c : chars) {
            adj.put(c, new HashSet<>());
            deg.put(c, 0);
        }
        for(int i = 0; i < n-1; i++) {
            String a = s[i], b = s[i+1];
            int len = Math.min(a.length(),b.length());
            int j = 0;
            while(j < len && a.charAt(j) == b.charAt(j)) {
                j++;
            }
            if(j == len && a.length() > b.length()) {
                System.out.println("IMPOSSIBLE");
                return;
            }
            if(j == len) continue;
            char u = a.charAt(j);
            char v = b.charAt(j);
            if(!adj.get(u).contains(v)) {
                adj.get(u).add(v);
                deg.put(v,deg.get(v)+1);
            }
        }
        Queue<Character> q = new ArrayDeque<>();
        for(Map.Entry<Character,Integer> entry : deg.entrySet()) {
            if(entry.getValue() == 0) {
                q.add(entry.getKey());
            }
        }
        String ans = "";
        while(!q.isEmpty()) {
            Character c = q.poll();
            ans += c;
            if(q.size() > 1) {
                System.out.println("AMBIGUOUS");
                return;
            }
            for(char v : adj.get(c)) {
                deg.put(v,deg.get(v)-1);
                if(deg.get(v)==0) {
                    q.add(v);
                }
            }
        }
        if(ans.length() < chars.size()) {
            System.out.println("IMPOSSIBLE");
        }
        else {
            System.out.println(ans);
        }
    }
}
