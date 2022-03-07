// Enes Şaşmaz 150170090 OOP-HW2 

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    string surname;
public:
    Person(string n, string sn)
    {
        setName(n);
        setSurname(sn);
    }
    void setName(const string& newname)
    {
        name = newname;
    }
    void setSurname(const string& newsurname)
    {
        surname = newsurname;
    }
    string getName()
    {
        return name;
    }
    string getSurname()
    {
        return surname;
    }
};


class Owner : public Person
{
public:
    Owner* head0 = NULL;
    Owner* next0 = NULL;
    Owner(string n, string sn):Person(string n, string sn){};
};



class Courier : public Person
{
    string vehicle;
public:
    Courier* head = NULL;
    Courier* next = NULL;
    Courier(string n, string sn, string vhc):Person(string n, string sn);
    void setVehicle(const string& newvehicle)
    {
        vehicle = newvehicle;
    }
    string getVehicle()
    {
        return vehicle;
    }
};

Courier::Courier(string n, string sn, string vhc):Person(string n, string sn)
{
    setVehicle(vhc);
}

class Business
{
private:
    string b_name;
    string address;
public:
    Courier* head = NULL;
    Courier* next = NULL;
    Owner* head0 = NULL;
    Owner* next0 = NULL;
    friend class Person;
    friend class Courier;
    friend class Owner;
    Business();
    void hire_courier(string courier_name, string courier_surname, string courier_vehicle);
    void list_couriers();
    void list_owners();
    int calculate_shipment_capacity();
    void operator();

};

Business::Business(string bname, string baddress, string* ownername, int size)
{
    b_name = bname;
    address = baddress;
    Owner* temp = head0;
    while (temp != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            ownername[i] = temp->getName + " " + temp->getSurname;
            temp = temp->next0;
        }
    }
}


void Business::hire_courier(string courier_name, string courier_surname, string courier_vehicle)
{
    Courier* temp = head;
    if (head == NULL)
    {
        head->getName() = courier_name;
        head->getSurname() = courier_surname;
        head->getVehicle() = courier_vehicle;
    }
    else if (head != NULL)
    {
        while (temp != NULL)
        {
            temp = temp->next;
        }
        temp->getName() = courier_name;
        temp->getSurname() = courier_surname;
        temp->getVehicle() = courier_vehicle;
    }
}

void Business::list_couriers()
{
    Courier* temp = head;

    while (temp != NULL)
    {
        cout << temp->getName() << " " << temp->getSurname() << " " << temp->getVehicle() << endl;
        temp = temp->next;
    }
}

void Business::list_owners()
{
    float ownership = 0;
    Owner* temp = head0;
    float counter = 0;

    while (temp != NULL)
    {
        temp = temp->next0;
        counter++;
    }

    ownership = 100 / counter;

    temp = head0;
    while (temp != NULL)
    {
        cout << temp->getName() << " " << temp->getSurname() << " " << ownership << endl;
        temp = temp->next0;
    }
}

int Business::calculate_shipment_capacity()
{
    Courier* temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        int total_capacity = 0;
        if (temp->getVehicle == "car")
        {
            total_capacity += 200;
        }
        if (temp->getVehicle == "motorcycle")
        {
            total_capacity += 35;
        }
        if (temp->getVehicle == "bicycle")
        {
            total_capacity += 10;
        }
        return total_capacity;
        temp = temp->next;
    }
}





int main() {
    // Create owners of the business
    //Constructor parameters: name, surname
    Owner o1 = Owner("Owner_name1", "surname1");
    Owner o2 = Owner("Owner_name2", "surname2");
    Owner* owner_arr = new Owner[2];
    owner_arr[0] = o1;
    owner_arr[1] = o1;

    //Crete the business itself
    //Constructor parameters: name, address, owner_array, number_of_owners
    Business atlas = Business("Atlas", "Maslak Istanbul/Turkey", owner_arr, 2);

    // Print owner info to screen: name, surname, ownership
    atlas.list_owners();

    // Add new employees
    // Constructor parameters: name, surname, vehicle_type
    Courier c1 = Courier("Courier", "surname1", "car");
    Courier c2 = Courier("Courier", "surname2", "motorcycle");
    Courier c3 = Courier("Courier", "surname3", "motorcycle");

    atlas.hire_courier(c1);
    atlas.hire_courier(c2);
    atlas.hire_courier(c3);


    // Print business info to screen
    // Name, address, owners, couriers
    atlas();

    // Get courier with index 1 and remove it from the list/array
    Courier cour = atlas[1];
    atlas.fire_courier(cour);

    // Print remaining couriers
    atlas.list_couriers();

    // Print current maximum shipment capacity
    std::cout << atlas.calculate_shipment_capacity() << std::endl;
    return 0;
}