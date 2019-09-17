#include "Cell.h"

Cell::Cell(int x, int y, char c): m_info{x, y, c} {}

void Cell::reset_state() {
    m_state.action = 's';
    m_state.direction = "P";
}

std::string Cell::which_dir(Subject &whoFrom, bool reverse){
    int south = whoFrom.get_info().y - this->get_info().y;
    int east = whoFrom.get_info().x - this->get_info().x;
    std::string dir;
    if(!reverse){
        south = 0 - south;
        east = 0 - east;
    }
    if ((!south) && (!east)){
        return "P";
    }
    if (south == 0){
        if (east > 0){
            dir = "ea";
        } else {
            dir = "we";
        }
    } else if (south > 0){
        if (east == 0){
            dir = "so";
        } else if (east > 0){
            dir = "se";
        } else {
            dir = "sw";
        }
    } else {
        if (east == 0){
            dir = "no";
        } else if (east > 0){
            dir = "ne";
        } else {
            dir = "nw";
        }
    }
    return dir;
}

Cell::Cell(Cell &c){
    m_info = c.get_info();

}

bool Cell::is_guarded(){
    return guarded;
}

void Cell::set_cord(int x, int y){
    m_info.x = x;
    m_info.y = y;
}