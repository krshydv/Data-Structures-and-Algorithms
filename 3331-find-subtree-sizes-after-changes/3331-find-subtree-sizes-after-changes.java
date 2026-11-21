import java.util.*;

class Solution {
    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;

        List<Integer>[] tree = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 1; i < n; i++) {
            tree[parent[i]].add(i);
        }

        int[] ans = new int[n];
        Arrays.fill(ans, 1);

        ArrayDeque<Integer>[] path = new ArrayDeque[26];

        for (int i = 0; i < 26; i++) {
            path[i] = new ArrayDeque<>();
        }

        int[] nodeStack = new int[2 * n];
        int[] parentStack = new int[2 * n];
        boolean[] exit = new boolean[2 * n];

        int top = 0;

        nodeStack[top] = 0;
        parentStack[top] = -1;
        exit[top++] = false;

        while (top > 0) {
            top--;

            int node = nodeStack[top];
            int par = parentStack[top];

            int c = s.charAt(node) - 'a';

            if (!exit[top]) {
                path[c].push(node);

                nodeStack[top] = node;
                parentStack[top] = par;
                exit[top++] = true;

                for (int i = tree[node].size() - 1; i >= 0; i--) {
                    int child = tree[node].get(i);

                    nodeStack[top] = child;
                    parentStack[top] = node;
                    exit[top++] = false;
                }
            } else {
                path[c].pop();

                int newParent;

                if (!path[c].isEmpty()) {
                    newParent = path[c].peek();
                } else {
                    newParent = par;
                }

                if (newParent != -1) {
                    ans[newParent] += ans[node];
                }
            }
        }

        return ans;
    }
}