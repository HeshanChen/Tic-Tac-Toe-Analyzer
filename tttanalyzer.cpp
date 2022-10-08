// Copyright 2022 Heshan Chen   ephsc@bu.edu
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "movedef.h"
using namespace std;
vector<string> get_all_boards();
char tttresult(string);
char tttresult(vector<Move>);
void ttt_tally();

void ttt_tally() {
    map <char, int> tally {
            {'t', 0},
            {'o', 0},
            {'x', 0},
            {'i', 0},
            {'c', 0},
    };

    string keys = "xotic";
    vector<string> s;
    s = get_all_boards();

    for (int i = 0; i < s.size(); i++) {
        char temp = tttresult(s.at(i));
        tally.at(temp) += 1;
    }
    cout << 'x' << " " << tally.at('x') << endl;
    cout << 'o' << " " << tally.at('o') << endl;
    cout << 't' << " " << tally.at('t') << endl;
    cout << 'i' << " " << tally.at('i') << endl;
    cout << 'c' << " " << tally.at('c') << endl;
}
char tttresult(string s) {
    if (s.size() != 9) {
        return 'e';
    }

    for (int i = 0; i < s.size(); ++i) {
        char temp = s.at(i);
        if (!(temp == 'x' || temp == 'o' || temp == '#')) {
            return 'e';
        }
    }
    int numx = 0;
    int numo = 0;

    for (int i = 0; i < s.size(); i++) {
        char temp = s.at(i);
        if (temp == 'x') {
            numx = numx + 1;
        } else if (temp == 'o') {
            numo = numo + 1;
        }
    }


    int xs = 0;
    int os = 0;

    char c = 'x';
    char d = 'o';
    if (s.at(0) == c && s.at(1) == c && s.at(2) == c) { xs += 1; }
    if (s.at(3) == c && s.at(4) == c && s.at(5) == c) { xs += 1; }
    if (s.at(6) == c && s.at(7) == c && s.at(8) == c) { xs += 1; }
    if (s.at(0) == c && s.at(3) == c && s.at(6) == c) { xs += 1; }
    if (s.at(1) == c && s.at(4) == c && s.at(7) == c) { xs += 1; }
    if (s.at(2) == c && s.at(5) == c && s.at(8) == c) { xs += 1; }
    if (s.at(0) == c && s.at(4) == c && s.at(8) == c) { xs += 1; }
    if (s.at(2) == c && s.at(4) == c && s.at(6) == c) { xs += 1; }
    if (s.at(0) == d && s.at(1) == d && s.at(2) == d) { os += 1; }
    if (s.at(3) == d && s.at(4) == d && s.at(5) == d) { os += 1; }
    if (s.at(6) == d && s.at(7) == d && s.at(8) == d) { os += 1; }
    if (s.at(0) == d && s.at(3) == d && s.at(6) == d) { os += 1; }
    if (s.at(1) == d && s.at(4) == d && s.at(7) == d) { os += 1; }
    if (s.at(2) == d && s.at(5) == d && s.at(8) == d) { os += 1; }
    if (s.at(0) == d && s.at(4) == d && s.at(8) == d) { os += 1; }
    if (s.at(2) == d && s.at(4) == d && s.at(6) == d) { os += 1; }

    if (numx - numo > 1 || numx - numo < -1) {
        return 'i';
    }

    int sb = 0;
    for (int i = 0 ; i < 9; i++) {
        if (s.at(i) != '#') {
            sb++;
        }
    }

    if (numx == numo) {
        if (os != 0) {
            if (xs == 0) {
                return 'o';
            } else {
                return 'i';
            }
        } else {
                if (xs != 0) {
                    return 'i';
                } else {
                    return 'c';
                }
        }
    } else if (numx == numo+1) {
        if (xs != 0) {
            if (os == 0) {
                return 'x';
            } else {
                return 'i';
            }
        } else if (sb == 9) {
            if (os != 0) {
                return 'i';
            } else {
                return 't';
            }
        } else {
            if (xs == 0 && os == 0) {
                return 'c';
            } else {
                return 'i';
            }
        }
    } else {
        return 'i';
    }
}

char tttresult(vector<Move> board) {
    string hs = "#########";
    for (int i = 0; i < board.size(); i++) {
        Move m = board.at(i);
        if (m.r > 2 || m.c >2) {
            return 'e';
        }
        int index = 3 * m.r + m.c;
        hs.at(index) = m.player;
        char result = tttresult(hs);
        if (result == 'e' || result == 'i' || result == 'x' || result == 'o' || result == 't') {
            return result;
        }
    }
    return tttresult(hs);
}

vector<string> get_all_boards() {
    vector<string> s;
    string keys = "xo#";
    string board;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    for (int m = 0; m < 3; ++m) {
                        for (int n = 0; n < 3; ++n) {
                            for (int i1 = 0; i1 < 3; ++i1) {
                                for (int j1 = 0; j1 < 3; ++j1) {
                                    for (int k1 = 0; k1 < 3; ++k1) {
                                        board = "";
                                        board += keys.at(i);
                                        board += keys.at(j);
                                        board += keys.at(k);
                                        board += keys.at(l);
                                        board += keys.at(m);
                                        board += keys.at(n);
                                        board += keys.at(i1);
                                        board += keys.at(j1);
                                        board += keys.at(k1);
                                        s.push_back(board);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return s;
}

// MAIN
int main() {
    ttt_tally();
    vector<string> m;
    return 0;
}
