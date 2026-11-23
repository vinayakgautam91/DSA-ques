class ProductOfNumbers {
    vector<int> pref;

public:
    ProductOfNumbers() {
        pref = {};
    }

    void add(int num) {
        if(num == 0) {
            pref.clear();
        }
        else {
            if(pref.empty()) {
                pref.push_back(num);
            }
            else {
                pref.push_back(pref.back() * num);
            }
        }
    }

    int getProduct(int k) {
        if(k > pref.size()) {
            return 0;
        }

        if(k == pref.size()) {
            return pref.back();
        }

        return pref.back() / pref[pref.size() - k - 1];
    }
};