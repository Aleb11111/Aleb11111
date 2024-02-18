//
// Created by Ale on 3/15/2023.
//

#ifndef A23_ALEB1111_UI_H
#define A23_ALEB1111_UI_H

#endif //A23_ALEB1111_UI_H

#pragma once
#include "Service.h"

typedef struct
{
    Service* service;
}UI;

UI* create_UI(Service* service);
void add_product_ui(UI* ui);
void delete_product_ui(UI* ui);
void update_product_ui(UI* ui);
void dislay_elements_by_string_ui(UI* ui);
void menu();
void start(UI* ui);
void display_by_category_ui(UI* ui);
void distroy_UI(UI* ui);

