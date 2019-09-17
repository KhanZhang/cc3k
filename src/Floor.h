#ifndef CS246A5_FLOOR_H
#define CS246A5_FLOOR_H

#include <vector>
#include <string>
#include <memory>
#include "Cell.h"
#include "Observer.h"
#include "Display.h"
#include "CellDecorator.h"

struct Cord {
    int x;
    int y;
};
class Floor : public Observer {
private:
    std::vector<std::vector<Cell*>> m_floor;
    std::vector<std::vector<Cell*>> m_rooms;
    size_t m_height, m_width;
    std::string m_race;
    Cord m_player;
    Cord m_stair;
    Display* m_display;
    bool m_compass_found = false;
    unsigned m_floor_num = 1;

    char get_cell_symbol(Cord);
    bool get_new_location(Cord &, std::string);
    bool is_floor(Cell *);
    void vanish(Subject &);
    Cell * get_cell(std::string);
    void random_move(Cell &c);
    bool move(std::string &direction, Cell &ce);
public:
    // Game manipulations
    explicit Floor(const std::string &map_file, char race);
    ~Floor() override;
    bool move(std::string &direction);
    bool use(std::string &direction);
    bool attack(std::string &direction);
    bool pickup(std::string &direction);
    bool reset();
    void generate_objects(int pc_room);
    void enemy_round();

    // Game info
    bool compass_found() const;

    // Observer
    void notify(Subject&) override;


    friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};


#endif //CS246A5_FLOOR_H
