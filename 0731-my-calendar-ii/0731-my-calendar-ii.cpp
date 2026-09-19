class MyCalendarTwo {
    map<int, int> m;

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {

        // Temporarily add the booking
        m[startTime]++;
        m[endTime]--;

        int cnt = 0;

        for (auto &[time, change] : m) {

            cnt += change;

            if (cnt >= 3) {
                // Undo the booking
                m[startTime]--;
                m[endTime]++;

                if (m[startTime] == 0)
                    m.erase(startTime);

                if (m[endTime] == 0)
                    m.erase(endTime);

                return false;
            }
        }

        return true;
    }
};