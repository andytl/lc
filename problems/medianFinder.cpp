#include "problems.h"

namespace medianFinder {
    class MedianFinder {
        priority_queue<int, vector<int>, less<int>> smaller;
        priority_queue<int, vector<int>, greater<int>> larger;
    public:
        /** initialize your data structure here. */
        MedianFinder() {
            
        }
        
        void addNum(int num) {
            if (smaller.empty() || num >= smaller.top()) {
                larger.push(num);
            } else {
                smaller.push(num);
            }
            if (smaller.size() > larger.size()) {
                larger.push(smaller.top());
                smaller.pop();
            } else if (smaller.size() + 1 < larger.size()) {
                smaller.push(larger.top());
                larger.pop();
            }
        }
        
        double findMedian() {
            if (larger.size() > smaller.size()) {
                return static_cast<double>(larger.top());
            } else {
                return static_cast<double>(larger.top() + smaller.top()) / 2;
            }
        }
    };


    TEST(medianFinder, T1) {
        MedianFinder mf;
        mf.addNum(1);
        mf.addNum(2);
        EXPECT_EQ(mf.findMedian(), 1.5);
        mf.addNum(3);
        EXPECT_EQ(mf.findMedian(), 2);
    }
    TEST(medianFinder, T2) {
        MedianFinder mf;
        mf.addNum(2);
        mf.addNum(3);
        mf.addNum(4);
        EXPECT_EQ(mf.findMedian(), 3);
    }
    TEST(medianFinder, T3) {
        MedianFinder mf;
        mf.addNum(2);
        mf.addNum(3);
        EXPECT_EQ(mf.findMedian(), 2.5);
    }
}