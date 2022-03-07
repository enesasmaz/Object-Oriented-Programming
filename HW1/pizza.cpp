#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


class pizza
{
private:
    string name;
    string size;
    const char** ingredients = new const char* [6];
    string crust_type;
    int small_count = 0;
    int medium_count = 0;
    int big_count = 0;
public:
    friend class drink;
    friend class orderlist;
    friend class order;
    pizza();
    pizza(string sizepizza, string crust, int pizza_type);
    pizza(const pizza& copy);
};

class order
{
private:
    string customer;
    pizza* pizza_orders = NULL;
    drink* drink_orders = NULL;
    pizza* nextpizza;
    drink* nextdrink;
    order* node;
public:
    friend class drink;
    friend class pizza;
    friend class orderlist;
    double getPrice();
    order(string customername, pizza* head_pizza, drink* head_drink, int amount, int chosendrink);
    order(string customername, pizza* head_pizza);
};

class drink
{
private:
    string name;
    int cola_count = 0;
    int soda_count = 0;
    int icetea_count = 0;
    int fruitjuice_count = 0;
public:
    friend class orderlist;
    friend class pizza;
    friend class order;
    drink(int drinknum);
};

drink::drink(int drinknum)
{
    if (drinknum == 1)
    {
        name = "Cola";
        cola_count++;
    }
    else if (drinknum == 2)
    {
        name = "Soda";
        soda_count++;
    }
    else if (drinknum == 3)
    {
        name = "Ice Tea";
        icetea_count++;
    }
    else if (drinknum == 4)
    {
        name = "Fruit Juice";
        fruitjuice_count++;
    }
}

double order::getPrice()
{
    int small_price = pizza_orders -> small_count * 15;
    int medium_price = pizza_orders -> medium_count * 20;
    int big_price = pizza_orders -> big_count * 25;
    int cola_price = (drink_orders -> cola_count) * 4;
    int soda_price = (drink_orders -> soda_count)  * 2;
    int icetea_price = (drink_orders -> icetea_count) * 3;
    float fruitjuice_price = (drink_orders -> fruitjuice_count) * 3.5;
    float total_price = small_price + medium_price + big_price + cola_price + soda_price + icetea_price + fruitjuice_price;
    return total_price;
}

order::order(string customername, pizza* head_pizza, drink* head_drink, int amount, int chosendrink)
{
    node = new order;
    node->customer = customername;
    node->pizza_orders = head_pizza;
    node->nextpizza = NULL;
    node->nextdrink = NULL;
    int i = 1;
    while (i < amount)
    {
        node->pizza_orders->nextpizza = new pizza(pizza_orders);
        i++;
    }
    n->drink_orders = head_drink;
    while (chosendrink != -1)
    {
        node->head_drink->nextdrink = new drink(chosendrink);
    }
}

order::order(string customername, pizza* head_pizza)
{
    node = new order;
    node->customer = customername;
    ndoe->pizza_orders = head_pizza;
    node->nextpizza = NULL;
    node->nextdrink = NULL;
    int i = 1;
    while (i < amount)
    {
        node->pizza_orders->nextpizza = new pizza(pizza_orders);
        i++;
    }
}

pizza::pizza()
{
    size = size_2;
    crust_type = crust_2;
    ingredients = "mozarella";
    medium_count++;
}

pizza::pizza(string sizepizza, string crust, int pizza_type)
{
    size = sizepizza;
    crust_type = crust;
    if (pizza_type == 1)
    {
        name = "Chicken Pizza";
        ingredients[0] = { "mozarella" };
        ingredients[1] = { "chicken" };
        ingredients[2] = { "mushroom" };
        ingredients[3] = { "corn" };
        ingredients[4] = { "onion" };
        ingredients[5] = { "tomato" };
    }
    else if (pizza_type == 2)
    {
        name = "Brocolli Pizza";
        ingredients[0] = { "mozarella" };
        ingredients[1] = { "broccoli" };
        ingredients[2] = { "pepperoni" };
        ingredients[3] = { "olive" };
        ingredients[4] = { "corn" };
        ingredients[5] = { "onion" };
    }
    else if (pizza_type == 3)
    {
        name = "Sausage Pizza";
        ingredients[0] = { "mozarella" };
        ingredients[1] = { "sausage" };
        ingredients[2] = { "tomato" };
        ingredients[3] = { "olive" };
        ingredients[4] = { "mushroom" };
        ingredients[5] = { "corn" };
    }
    if (size == "small")
    {
        small_count++;
    }
    else if (size == "medium")
    {
        medium_count++;
    }
    else if (size == "big")
    {
        big_count++;
    }
}
pizza::pizza(const pizza& copy)
{
    name = copy.name;
    size = copy.size;
    crust_type = copy.crust_type;
    int j = 0;

    for (int i = 0; i <= 6; i++) {

        if (copy.ingredients[i] != NULL)
        {
            ingredients[j] = copy.ingredients[i];
            j++;
        }
    }
}

class orderlist
{
private:
    int n;
    order* head;
public:
    friend class drink;
    friend class pizza;
    friend class order;
    void orderlist();
    void takeorder();
    void listorders();
    void deliverorders();
};

orderlist::orderlist()
{
    n = 0;
    head = NULL;
}

void orderlist::takeorder()
{
    string name;
    int amount = 0;
    int select = -1;
    int choose = -1;
    int selected = -2;
    string order_size;
    string order_crust;


    cout << "Pizza Menu" << endl;
    cout << "1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)" << endl;
    cout << "2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)" << endl;
    cout << "3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)" << endl;
    cout << "0. Back to main menu" << endl;
    cin >> select;

    if (select != 0) {

        cout << "Select size: small(15 TL), medium (20 TL), big (25 TL)" << endl;
        cin >> order_size;
        cout << "Select crust type: thin, normal, thick" << endl;
        cin >> order_crust;
        cout << "Enter the amount:";
        cin >> amount;
        cout << endl;

        pizza_orders = new pizza(order_size, order_crust, select);
    }
    cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;
    for (int i = 0; i < 6; i++) {
        cout << (i + 1) << ". " << pizza_orders->ingredients[i] << endl;
    }

    cout << "Press 0 to save it." << endl;
    while (choose != 0)
    {
        cin >> choose;
        pizza_orders->ingredients[choose - 1] = "";
    }

    cout << "Please choose a drink:" << endl;
    cout << "0. no drink" << endl;
    cout << "1. cola 4 TL" << endl;
    cout << "2. soda 2 TL" << endl;
    cout << "3. ice tea 3 TL" << endl;
    cout << "4. fruit juice 3.5 TL" << endl;
    cout << "Press -1 for save your order" << endl;

    while (selected != -1)
    {
        cin >> selected;

        if (drink_orders == NULL)
        {
            drink_orders = new drink(selected);
        }
        else
        {
            drink_orders->nextdrink = new drink(selected);
        }

    }
    cout << "Please enter your name:" << endl;
    cin >> name;
    cout << endl;

    if (head == NULL)
    {
        head = new order(name, pizza_orders, drink_orders->nextdrink);
    }
    else
    {
        order* pizzatemp = head;
        while (pizzatemp->nextpizza != NULL)
        {
            pizzatemp = pizzatemp->pizzanext;
        }
        pizzatemp->pizzanext = new order(name, pizza_orders, drink_orders->nextdrink)
    }

    cout << "Your order is saved, it will be delivered when it is ready..." << endl;


}

void orderlist::listorders()
{
    order* temp;
    temp = head;

    while (temp != NULL)
    {
        cout << "Name: " << temp->customer << endl << endl;
        cout << temp->pizza_orders->name;
        cout << "(";
        for (int i = 0; i < 6; i++)
        {
            if (temp->pizza_orders->ingredients[i] != "")
            {
                cout << temp->pizza_orders->ingredients[i] << ",";
            }
        }
        cout << ")" << endl;
        cout << " size: " << temp->pizza_orders->size << ", crust: " << temp->pizza_orders->crust_type << endl << endl;

        if (cola_count != 0)
        {
            cout << cola_count << "Cola";
        } if (soda_count != 0 || icetea_count != 0 || fruitjuice_count != 0)
        {
            cout << ", ";
        } if (soda_count != 0)
        {
            cout << soda_count << "Soda"
        } if (cola_count != 0 || icetea_count != 0 || fruitjuice_count != 0)
            {
                cout << ", ";
            } if (icetea_count != 0)
            {
                cout << icetea_count << "Ice Tea"
            } if (cola_count != 0 || soda_count != 0 || fruitjuice_count != 0)
                {
                    cout << ", ";
                } if (fruitjuice_count != 0)
                {
                    cout << fruitjuice_count << "Fruit Juice"
                }

                cout << endl;
                temp = temp->nextpizza;
    }

}

void orderlist::deliverorders()
{
    string name;
    if (head != NULL)
    {
        cout << "Please write the customer name in order to deliver his/her order:";
        cin >> name;
        cout << "Following order is delivering..." << endl;

        order* temp;
        temp = head;
        if (head->customer == name)
        {
            cout << "Name: " << temp->customer << endl << endl;
            cout << temp->pizza_orders->name;
            cout << "(";
            for (int i = 0; i < 6; i++)
            {
                if (temp->pizza_orders->ingredients[i] != "")
                {
                    cout << temp->pizza_orders->ingredients[i] << ",";
                }
            }
            cout << ")" << endl;
            cout << " size: " << temp->pizza_orders->size << ", crust: " << temp->pizza_orders->crust_type << endl << endl;

            if (cola_count != 0)
            {
                cout << cola_count << "Cola";
            } if (soda_count != 0 || icetea_count != 0 || fruitjuice_count != 0)
            {
                cout << ", ";
            } if (soda_count != 0)
            {
                cout << soda_count << "Soda"
            } if (cola_count != 0 || icetea_count != 0 || fruitjuice_count != 0)
                {
                    cout << ", ";
                } if (icetea_count != 0)
                {
                    cout << icetea_count << "Ice Tea"
                } if (cola_count != 0 || soda_count != 0 || fruitjuice_count != 0)
                    {
                        cout << ", ";
                    } if (fruitjuice_count != 0)
                    {
                        cout << fruitjuice_count << "Fruit Juice"
                    }

                    cout << endl;
                    cout << "Total price: " << getPrice() << endl;
                    temp = temp->nextpizza;
        }
    }
}

int main() {
    string comma = ", ";
    string size_1 = "small";
    string size_2 = "medium";
    string size_3 = "big";
    string ing_1 = "mozarella";
    string ing_2 = "chicken";
    string ing_3 = "mushroom";
    string ing_4 = "corn";
    string ing_5 = "onion";
    string ing_6 = "tomato";
    string ing_7 = "broccoli";
    string ing_8 = "pepperoni";
    string ing_9 = "olive";
    string ing_10 = "sausage";
    string crust_1 = "thick";
    string crust_2 = "normal";
    string crust_3 = "tihn";
    string drink_1 = "Cola";
    string drink_2 = "Soda";
    string drink_3 = "Ice Tea";
    string drink_4 = "Fruit Juice";

    int menu = -1;

    orderlist pizzaorder;

    while (menu != 5) {

        cout << "Welcome to Unicorn Pizza!" << endl;
        cout << "1. Add an order" << endl;
        cout << "2. List orders" << endl;
        cout << "3. Deliver order" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose what to do: ";
        cin >> menu;
        cout << endl;

        if (menu == 1)
        {
            pizzaorder.takeOrder();

        }
        else if (menu == 2)
        {
            pizzaorder.listOrder();

        }
        else if (menu == 3)
        {
            pizzaorder.deliverOrders();

        }
        else if (menu == 4)
        {
            break;
        }

        cout << endl;
    }

    cout << "Goodbye";

    return 0;
}