#include "Display.h"

#include <algorithm>
#include "Cell.h"
using namespace std;

Display::Display(size_t w, size_t h): m_w {w}, m_h {h} {
    vector<char> col;
    col.resize(h);
    fill(col.begin(), col.end(),' ');

    m_display.resize(w);
    // Use std::fill
    fill(m_display.begin(), m_display.end(), col);
}

void Display::notify(Subject &who) {
    Info info = who.get_info();
    //cout << info.x << ' ' << info.y << info.symbol << endl;
    m_display[info.x][info.y] = info.symbol;
}

ostream &operator<<(ostream &out, const Display &d) {
    for (int y = 0; y < d.m_h; ++y) {
        for (int x = 0; x < d.m_w; ++x) {
            out << d.m_display[x][y];
        }
        out << endl;
    }
    out << endl;
    return out;
}