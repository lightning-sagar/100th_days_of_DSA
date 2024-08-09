class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        constexpr int N = 1000;
        for (int i = 1; i <= N; ++i) {
          s.emplace(i);
        }
    }

    int popSmallest() {
        const int res = *s.begin();
        s.erase(s.begin());
        return res;
    }

    void addBack(int num) {
        s.emplace(num);
    }

private:
    set<int> s;
};

