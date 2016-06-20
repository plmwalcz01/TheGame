#pragma once

class Items : public Effect
{
    private:
    int max_durability;
    int max_price;
    int max_weight;
    int max_stack;

    public:
    int durability;
    int price;
    int weight;
    int stack;
    Effect passive_item_effect;
    Effect active_effect;

    void Items::Items();
    int effect();
    int set_current_price();
    int decrease_durability(int);
    int increase_durability(int);
};
