stack<int> st;
         for (int i = 0; i < n; ++i) {
            st.push(i);
        }

        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
             if (M[a][b]) {
                st.push(b);
            }
            else {
                st.push(a);
            }
        }

                int celebrityCandidate = st.top(); st.pop();
        for (int i = 0; i < n; ++i) {
            if (i != celebrityCandidate && (M[i][celebrityCandidate] == 0 || M[celebrityCandidate][i] == 1)) {
                                 return -1;
            }
        }
        return celebrityCandidate;