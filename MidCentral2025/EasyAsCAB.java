import java.util.*;

// c++ for some reason handles utf strings non-natively, so this is in java

// first, notice that we can represent the relations between characters as a directed graph
// such that if we have strings "C", "B" then we can create an edge between "C" and "B" pointing towards "B" meaning "C" must come before "B"
// now we have created a classical topological sort problem similar to Course Scheduling 2 and Alien Dictionary on leetcode 
// the relationship between two different strings is the first character that differs
// for example, if we have "ABC" and "ADC", we know that B must come before D
// if one string is a prefix of another, the shorter string must come first
// otherwise, no character ordering can satisfy the given strings, so the answer is IMPOSSIBLE
// now that the relations have been created we ned to figure out the ordering
// the character with indegree of 0 must be the first character in the alphabet
// the ordering can be solved through a topological sort
// in this solution i used kahn's algorithm
// one thing to keep of note is the problem asks to determine if the answer is AMBIGUOUS
// this can be found the size of the current queue is > 1 because this means there are multiple possible
// choices for a character at the position
// but this doesn't guarantee AMBIGUOUS because it is still possible the answer is IMPOSSIBLE
// the answer is impossible if the alphabet constructed doesn't contain all of the characters


public class EasyAsCAB {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = Integer.parseInt(scan.nextLine());
        String[] s = new String[n];
        for(int i = 0; i < n; i++) {
            s[i] = scan.nextLine();
        }

        Set<Character> chars = new HashSet<>();
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

        StringBuilder ans = new StringBuilder();
        boolean ambiguous = false;

        while(!q.isEmpty()) {
            if(q.size() > 1) {
                ambiguous = true;
            }

            Character c = q.poll();
            ans.append(c);

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
        else if(ambiguous) {
            System.out.println("AMBIGUOUS");
        }
        else {
            System.out.println(ans);
        }
    }
}
