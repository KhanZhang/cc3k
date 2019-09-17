#include "Floor.h"

#include "BasicCell.h"
#include "Human.h"
#include "Orc.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Dragonborn.h"
#include "Potions.h"
#include "Treasure.h"
#include "Werewolf.h"
#include "Vampire.h"
#include "Goblin.h"
#include "Troll.h"
#include "Phoenix.h"
#include "Merchant.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Return '\0' if such cell does not exists
char Floor::get_cell_symbol(Cord c) {
    if (c.x >= 0 && c.x < m_width - 1 && c.y >= 0 && c.y < m_height - 1) {
        return m_floor[c.x][c.y]->get_info().symbol;
    } else {
        return '\0'; // Show that such cell DNE
    }
}

bool Floor::is_floor(Cell *c) {
    return c->get_info().symbol == '.' && c->get_info().x != m_stair.x && c->get_info().y != m_stair.y;
}

bool Floor::get_new_location(Cord &c, std::string direction) {
    if (direction == "no") {
        c.y--;
    } else if (direction == "ea") {
        c.x++;
    } else if (direction == "we") {
        c.x--;
    } else if (direction == "so") {
        c.y++;
    } else if (direction == "nw") {
        c.x--;
        c.y--;
    } else if (direction == "ne") {
        c.x++;
        c.y--;
    } else if (direction == "sw") {
        c.x--;
        c.y++;
    } else if (direction == "se") {
        c.x++;
        c.y++;
    } else {
        // Invalid input
        return false;
    }
    char tar = m_floor[c.x][c.y]->get_info().symbol;
    if ((tar != ' ') &&
        (tar != '-') &&
        (tar != '|')){
        return true;
    } else {
        return false;
    }
}

Floor::Floor(const string &map_file, char race) {
    srand(1111);

    ifstream map {map_file};
    stringstream ss;
    string line;

    getline(map, line);
    ss.str(line);
    ss >> m_width >> m_height;
    m_display = new Display{m_width, m_height};

    // Generate m_floor with enough space
    vector<Cell*> col;
    col.resize(m_height);
    fill(col.begin(), col.end(), nullptr);

    m_floor.resize(m_width);
    // Use std::fill
    fill(m_floor.begin(), m_floor.end(), col);

    // Read file
    while (getline(map, line)) {
        if (line == "BORDER") {
            getline(map, line);
            while (line != "DONE") {
                ss.str(line);
                ss.clear();
                char sym;
                Cord init_cord;
                Cord end_cord;
                ss >> sym >> init_cord.x >> init_cord.y >> end_cord.x >> end_cord.y;
                for (int x = init_cord.x; x <= end_cord.x; ++x) {
                    for (int y = init_cord.y; y <= end_cord.y; ++y) {
                        CellDecorator * new_cell = new CellDecorator {x, y, sym};
                        new_cell->attach(m_display);
                        new_cell->notify_observers();
                        m_floor[x][y] = new_cell;
                    }
                }
                getline(map, line);
            }
        } else if (line == "ROOM") {
            getline(map, line);

            vector<Cell *> room;
            while (line != "DONE") {
                ss.str(line);
                ss.clear();
                char sym;
                Cord init;
                Cord end;
                ss >> sym >> init.x >> init.y >> end.x >> end.y;

                for (int x = init.x; x <= end.x; ++x) {
                    for (int y = init.y; y <= end.y; ++y) {
                        CellDecorator *n_cell = new CellDecorator {x, y, sym};
                        n_cell->attach(m_display);
                        //n_cell->attach(this);
                        n_cell->notify_observers();
                        m_floor[x][y] = n_cell;
                        room.push_back(n_cell);
                    }
                }
                getline(map, line);
            }
            m_rooms.push_back(room);
        } else if (line == "PATH") {
            getline(map, line);
            while (line != "DONE") {
                ss.str(line);
                ss.clear();
                Cord init;
                Cord end;
                ss >> init.x >> init.y >> end.x >> end.y;

                for (int x = init.x; x <= end.x; ++x) {
                    for (int y = init.y; y <= end.y; ++y) {
                        CellDecorator *n_cell = new CellDecorator {x, y, '#'};
                        n_cell->attach(m_display);
                        n_cell->notify_observers();
                        m_floor[x][y] = n_cell;
                    }
                }
                getline(map, line);
            }
        }
    }

    // Fill rest cells with empty cell
    for (int x = 0; x < m_width; ++x) {
        for (int y = 0; y < m_height; ++y) {
            if (m_floor[x][y] == nullptr) {
                m_floor[x][y] = new CellDecorator {x, y, ' '};
                m_floor[x][y]->notify_observers();
            }
        }
    }

    // Add neighbours
    for (int x = 0; x < m_width; ++x) {
        for (int y = 0; y < m_height; ++y) {
            Cell *current = m_floor[x][y];
            // NW
            if (get_cell_symbol(Cord{x - 1, y - 1}) == '.') {
                current->attach(m_floor[x - 1][y - 1]);
            }
            // N
            if (get_cell_symbol(Cord{x, y - 1}) == '.') {
                current->attach(m_floor[x][y - 1]);
            }
            // NE
            if (get_cell_symbol(Cord{x + 1, y - 1}) == '.') {
                current->attach(m_floor[x + 1][y - 1]);
            }
            // W
            if (get_cell_symbol(Cord{x - 1, y}) == '.') {
                current->attach(m_floor[x - 1][y]);
            }
            // E
            if (get_cell_symbol(Cord{x + 1, y}) == '.') {
                current->attach(m_floor[x + 1][y]);
            }
            // SW
            if (get_cell_symbol(Cord{x - 1, y + 1}) == '.') {
                current->attach(m_floor[x - 1][y + 1]);
            }
            // S
            if (get_cell_symbol(Cord{x, y + 1}) == '.') {
                current->attach(m_floor[x][y + 1]);
            }
            // SE
            if (get_cell_symbol(Cord{x + 1, y + 1}) == '.') {
                current->attach(m_floor[x + 1][y + 1]);
            }
        }
    }

    // Generate main character
    int pc_room = rand() % m_rooms.size();
    int pc_room_size = m_rooms[pc_room].size();
    int pc_room_cell_i = rand() % pc_room_size;
    Cell * pc_c = m_rooms[pc_room][pc_room_cell_i];
    m_player.x = pc_c->get_info().x;
    m_player.y = pc_c->get_info().y;

    if (race == 'h') {
        m_floor[m_player.x][m_player.y]->cell_attach(new Human {m_floor[m_player.x][m_player.y]});
        m_race = "Human";
    } else if (race == 'e') {
        m_floor[m_player.x][m_player.y]->cell_attach(new Elf {m_floor[m_player.x][m_player.y]});
        m_race = "Elf";
    } else if (race == 'd') {
        m_floor[m_player.x][m_player.y]->cell_attach(new Dwarf {m_floor[m_player.x][m_player.y]});
        m_race = "Dwarf";
    } else if (race == 'o') {
        m_floor[m_player.x][m_player.y]->cell_attach(new Orc {m_floor[m_player.x][m_player.y]});
        m_race = "Orc";
    } else if (race == 'r') {
        m_floor[m_player.x][m_player.y]->cell_attach(new Dragonborn {m_floor[m_player.x][m_player.y]});
        m_race = "Dragonborn";
    }

    m_floor[m_player.x][m_player.y]->attach(m_display);
    m_floor[m_player.x][m_player.y]->notify_observers();

    generate_objects(pc_room);
}

Floor::~Floor() {
    delete m_display;
    for (auto &x : m_floor) {
        for (auto &y : x) {
            delete y;
        }
    }
}

bool Floor::move(std::string &direction, Cell &ce) {
    Cord c = {ce.get_info().x, ce.get_info().y};
    Cord n_cord {c.x, c.y};
    if (get_new_location(n_cord, direction)) { // get_new_location return true if in border
        char destination_symbol = get_cell_symbol(n_cord);
        // New block is an common floor block
        if (destination_symbol == '.' || destination_symbol == '+' || destination_symbol == '#') {
            Cell * player = m_floor[ce.get_info().x][ce.get_info().y]->cell_detach();
            m_floor[n_cord.x][n_cord.y]->cell_attach(player);

            m_floor[ce.get_info().x][ce.get_info().y]->notify_observers();
            m_floor[n_cord.x][n_cord.y]->set_state(State {'m', direction});
            m_floor[n_cord.x][n_cord.y]->notify_observers();
            m_floor[n_cord.x][n_cord.y]->reset_state();
            m_player = n_cord;
        } else if (destination_symbol == 'G' || destination_symbol == 'B') { // Gold or Barrier suit
            if (m_floor[ce.get_info().x][ce.get_info().y]->get_info().symbol != '@') {
                return false;
            }
            if(!pickup(direction)) {
                return false;
            } else {
                move(direction, ce);
                return true;
            }
        }
    }
    return false;
}

bool Floor::move(std::string &direction){
    return move(direction, *m_floor[m_player.x][m_player.y]);
}

Cell * Floor::get_cell(std::string direction){
    Cord c = {0, 0};
    if (direction == "no") {
        c.y--;
    } else if (direction == "ea") {
        c.x++;
    } else if (direction == "we") {
        c.x--;
    } else if (direction == "so") {
        c.y++;
    } else if (direction == "nw") {
        c.x--;
        c.y--;
    } else if (direction == "ne") {
        c.x++;
        c.y--;
    } else if (direction == "sw") {
        c.x--;
        c.y++;
    } else if (direction == "se") {
        c.x++;
        c.y++;
    } else {
        // Invalid input
        return nullptr;
    }
    Cell * tar = m_floor[m_player.x+c.x][m_player.y+c.y];
    if ((tar->get_info().symbol == '-') || (tar->get_info().symbol == '|')){
        return nullptr;
    } else {
        return m_floor[m_player.x + c.x][m_player.y + c.y];
    }
}

bool Floor::pickup(std::string &direction){
    Cell * tar = get_cell(direction);
    if (tar == nullptr){
        return false;
    } else {
        if (tar->is_guarded()){
            return false;
        } else {
            Cell * plr = m_floor[m_player.x][m_player.y];
            plr->set_state(State{'u', direction});
            plr->notify_observers();
            plr->reset_state();
            vanish(*tar);
            return true;
        }
    }
}

bool Floor::use(std::string &direction){
    Cell * tar = get_cell(direction);
    if (tar == nullptr){
        return false;
    } else {
        if (tar->get_info().symbol == 'P'){
            Cell * plr = m_floor[m_player.x][m_player.y];
            plr->set_state(State{'u', direction});
            plr->notify_observers();
            plr->reset_state();
            vanish(*tar);
            tar->notify_observers();
            return true;
        } else {
            return false;
        }
    }
}

bool Floor::attack(std::string &direction){
    Cell * tar = get_cell(direction);
    if (tar == nullptr){
        return false;
    } else {
        Cell * plr = m_floor[m_player.x][m_player.y];
        plr->set_state(State{'a', direction});
        plr->notify_observers();
        plr->reset_state();
        if (tar->get_info().hp == 0) {
            delete tar->cell_detach();
            tar->notify_observers();
        }
        return true;
    }
}

bool Floor::compass_found() const {
    return m_compass_found;
}

void Floor::notify(Subject &whoFrom){
    if (whoFrom.get_state().action == 'd'){
        char s = whoFrom.get_info().symbol;
        int x = whoFrom.get_info().x;
        int y = whoFrom.get_info().y;
        Treasure * n_c;
        if (s == 'M'){
            n_c = new Treasure {m_floor[x][y], 4};
        }
        vanish(whoFrom);
        m_floor[x][y]->notify_observers();
        if (s == 'M'){
            m_floor[x][y]->cell_attach(n_c);
        }
    } else if (whoFrom.get_info().symbol == 'C'){
        if (whoFrom.get_state().action == 'u'){
            vanish(whoFrom);
            m_compass_found = true;
        }
    }
}

void Floor::vanish(Subject &whoFrom){
    /*
    Cell * tar = m_floor[whoFrom.get_info().x][whoFrom.get_info().y];
    m_floor[whoFrom.get_info().x][whoFrom.get_info().y] = tar->cell_detach();
    delete tar;
     */
    delete m_floor[whoFrom.get_info().x][whoFrom.get_info().y]->cell_detach();
}

std::ostream &operator<<(std::ostream &out, const Floor &f) {
    out << *f.m_display;
    Cell * player = f.m_floor[f.m_player.x][f.m_player.y];
    out << "Race: " << f.m_race << " Gold: " << player->get_info().gold << endl;
    out << "HP: " << player->get_info().hp << endl;
    out << "Atk: " << player->get_info().atk << endl;
    out << "Def: " << player->get_info().def << endl;
    return out;
}

bool Floor::reset(){
    if (m_floor_num == 5){
        return false;
    }
    m_floor_num++;
    Cell * plr = m_floor[m_player.x][m_player.y];
    plr->reset_state();

    for (auto &x : m_floor) {
        for (auto &y : x) {
            char n = y->get_info().symbol;
            if (n == '@'){
                m_floor[y->get_info().x][y->get_info().y] = y->cell_detach();
            } else if ((n != '-') && (n != '|') && (n != '.') && (n != '+') && (n != '#') && (n != ' ')){
                vanish(*y);
            }
        }
    }

    int pc_room = rand() % m_rooms.size();
    int pc_room_size = m_rooms[pc_room].size();
    int pc_room_cell_i = rand() % pc_room_size;
    Cell * pc_c = m_rooms[pc_room][pc_room_cell_i];
    m_player.x = pc_c->get_info().x;
    m_player.y = pc_c->get_info().y;

    plr->upstair(m_floor[m_player.x][m_player.y]);
    generate_objects(pc_room);
}

void Floor::generate_objects(int pc_room){
    // Generate stair
    int stair_room = rand() % m_rooms.size();
    while (stair_room == pc_room) {
        // Prevent stair is in the same room
        stair_room = rand() % m_rooms.size();
    }
    int stair_room_cell = rand() % m_rooms[stair_room].size();
    m_stair.x = m_rooms[stair_room][stair_room_cell]->get_info().x;
    m_stair.y = m_rooms[stair_room][stair_room_cell]->get_info().y;

    // Generate potions
    for (int p = 0; p < 10; p++) {
        int potion_room, potion_room_cell;
        do {
            potion_room = rand() % m_rooms.size();
            potion_room_cell = rand() % m_rooms[potion_room].size();
        } while (not is_floor(m_rooms[potion_room][potion_room_cell]));

        int potion_type = rand() % 6;
        Mod potion_mod {0, 0, 0, 0};
        string potion_name;
        if (potion_type == 1) {
            potion_name = "RH";
            potion_mod.hp_up = 10;
        } else if (potion_type == 2) {
            potion_name = "BA";
            potion_mod.atk_up = 5;
        } else if (potion_type == 3) {
            potion_name = "BD";
            potion_mod.def_up = 5;
        } else if (potion_type == 4) {
            potion_name = "PH";
            potion_mod.hp_up = -5;
        } else if (potion_type == 5) {
            potion_name = "WA";
            potion_mod.atk_up = -5;
        } else {
            potion_name = "WD";
            potion_mod.def_up = -5;
        }

        Potions * n_p = new Potions {potion_mod, m_rooms[potion_room][potion_room_cell], potion_name};
        m_rooms[potion_room][potion_room_cell]->cell_attach(n_p);
        m_floor[n_p->get_info().x][n_p->get_info().y]->cell_attach(n_p);
        n_p->attach(m_display);
        n_p->notify_observers();
    }

    // Generate gold
    for (int g = 0; g < 10; ++g) {
        int gold_room, gold_room_cell;
        do {
            gold_room = rand() % m_rooms.size();
            gold_room_cell = rand() % m_rooms[gold_room].size();
        } while (not is_floor(m_rooms[gold_room][gold_room_cell]));

        int gold_type = rand() % 8;
        int gold_amount = 1;
        if (gold_type == 5) {
            gold_amount = 6;
        } else if (gold_type >= 6) {
            gold_amount = 2;
        }
        Treasure * n_c = new Treasure {m_rooms[gold_room][gold_room_cell], gold_amount};
        m_rooms[gold_room][gold_room_cell]->cell_attach(n_c);
        m_floor[n_c->get_info().x][n_c->get_info().y]->cell_attach(n_c);
        n_c->attach(m_display);
        n_c->notify_observers();
    }

    // Generate enemy
    for (int e = 0; e < 20; ++e) {
        int e_room, e_room_cell;
        do {
            e_room = rand() % m_rooms.size();
            e_room_cell = rand() % m_rooms[e_room].size();
        } while (not is_floor(m_rooms[e_room][e_room_cell]));

        Cell * n_e = nullptr;
        int e_x = m_rooms[e_room][e_room_cell]->get_info().x;
        int e_y = m_rooms[e_room][e_room_cell]->get_info().y;
        Cell * cur = m_rooms[e_room][e_room_cell];
        int e_rand = rand() % 18;
        if (e_rand < 4) { // Werewolf
            n_e = new Werewolf {cur};
        } else if (e_rand < 7) {
            n_e = new Vampire {cur};
        } else if (e_rand < 12) {
            n_e = new Goblin {cur};
        } else if (e_rand < 14) {
            n_e = new Troll {cur};
        } else {
            n_e = new Merchant {cur};
        }

        m_floor[e_x][e_y]->cell_attach(n_e);
        //m_rooms[e_room][e_room_cell]->cell_attach(n_e);
        n_e->attach(m_display);
        n_e->notify_observers();
    }
}

void Floor::random_move(Cell &c){
    int x = c.get_info().x;
    int y = c.get_info().y;
    if ((abs(x - m_player.x) <= 1) && (abs(y - m_player.y) <= 1)){
        c.set_state(State{'m', "P"});
        c.notify_observers();
        c.reset_state();
        return;
    } else {
        bool moved = false;
        //do {
        int dir = rand() % m_rooms.size();
        std::string direct;
        if (dir == 0) {
            direct = "ea";
        } else if (dir == 1) {
            direct = "we";
        } else if (dir == 2) {
            direct = "so";
        } else if (dir == 3) {
            direct = "no";
        } else if (dir == 4) {
            direct = "se";
        } else if (dir == 5) {
            direct = "ne";
        } else if (dir == 6) {
            direct = "sw";
        } else if (dir == 7) {
            direct = "nw";
        }
        moved = move(direct, c);
        //} while (!moved);
    }
}

void Floor::enemy_round(){
    for (auto &x : m_floor) {
        for (auto &y : x) {
            if (y->get_info().is_monster){
                random_move(*y->get_cell());
            }
        }
    }
}