class Robot {
public:
    int w, h, x, y, dir, per;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        per = 2 * (w + h) - 4;
    }

    void step(int num) {
        if (per == 0) return;

        num %= per;

        if (num == 0) {
            if (x == 0 && y == 0) {
                dir = 3;
                return;
            } else {
                num = per;
            }
        }

        while (num > 0) {
            if (dir == 0) {
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (move == 0) dir = 1;
            } 
            else if (dir == 1) {
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (move == 0) dir = 2;
            } 
            else if (dir == 2) {
                int move = min(num, x);
                x -= move;
                num -= move;
                if (move == 0) dir = 3;
            } 
            else {
                int move = min(num, y);
                y -= move;
                num -= move;
                if (move == 0) dir = 0;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (x == 0 && y == 0 && dir == 3) return "South";
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};