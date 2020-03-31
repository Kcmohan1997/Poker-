#include "mainwin.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Mainwin::Mainwin()
  : betButton{Gtk::manage(new Gtk::Button{"Bet"})},
    checkButton{Gtk::manage(new Gtk::Button{"Check"})},
    foldButton{Gtk::manage(new Gtk::Button{"Fold"})},
    swapButton{Gtk::manage(new Gtk::Button{"Swap"})},
    card1{Gtk::manage(new Gtk::Label{"Card 1"})},
    card2{Gtk::manage(new Gtk::Label{"Card 2"})},
    card3{Gtk::manage(new Gtk::Label{"Card 3"})},
    card4{Gtk::manage(new Gtk::Label{"Card 4"})},
    card5{Gtk::manage(new Gtk::Label{"Card 5"})},
    betAmount{Gtk::manage(new Gtk::Label{"$ Bet Amount"})},
    totalAmount{Gtk::manage(new Gtk::Label{"$ Total Amount"})}
{
    // Gui Setup

    set_default_size(800, 600);
    set_title(APP_TITLE);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);
    //Header Hbox
    Gtk::Box *hbox0 = Gtk::manage(new Gtk::HBox);
    vbox->pack_start(*hbox0, Gtk::PACK_SHRINK, 0);
    Gtk::Label *time = Gtk::manage(new Gtk::Label{"Time"});
    hbox0->pack_start(*time, Gtk::PACK_SHRINK, 0);
    time->set_hexpand(true);
    Gtk::Label *playerName = Gtk::manage(new Gtk::Label{"Player Name"});
    Gtk::Entry *playerEntry = Gtk::manage(new Gtk::Entry);
    hbox0->pack_start(*playerName, Gtk::PACK_SHRINK, 0);
    hbox0->pack_start(*playerEntry, Gtk::PACK_SHRINK, 0);

    // Card Display
    // Hbox of 5 labels, labels will be changable after integratio with dealer.
    Gtk::Box *hbox = Gtk::manage(new Gtk::HBox);
    vbox->pack_start(*hbox);
    
    hbox->pack_start(*card1);
    hbox->pack_start(*card2);
    hbox->pack_start(*card3);
    hbox->pack_start(*card4);
    hbox->pack_start(*card5);
    //Interactive zone of buttons and labels held in another hbox
    Gtk::Box *hbox2 = Gtk::manage(new Gtk::HBox);
    vbox->pack_start(*hbox2);
    hbox2->pack_start(*betButton);
    betButton->signal_clicked().connect([this] {this->on_bet_click();});
    hbox2->pack_start(*checkButton);
    checkButton->signal_clicked().connect([this] {this->on_check_click();});
    hbox2->pack_start(*foldButton);
    foldButton->signal_clicked().connect([this] {this->on_fold_click();});
    hbox2->pack_start(*swapButton);
    swapButton->signal_clicked().connect([this] {this->on_swap_click();});
    Gtk::Box *vbox2 = Gtk::manage(new Gtk::VBox);
    Gtk::Label *chatBox = Gtk::manage(new Gtk::Label{"Chat Area"});
    Gtk::Label *chatField = Gtk::manage(new Gtk::Label{"Chat field"});
    hbox2->pack_start(*vbox2);
    vbox2->pack_start(*chatBox, Gtk::PACK_SHRINK, 0);
    chatBox->override_background_color(Gdk::RGBA{"gray"});
    chatField->override_background_color(Gdk::RGBA{"white"});
    vbox2->pack_start(*chatField);
    chatField->set_hexpand(true);
    chatField->set_vexpand(true);
    Gtk::Grid *grid = Gtk::manage (new Gtk::Grid);
    Gtk::Label *space = Gtk::manage(new Gtk::Label{});
    space->set_vexpand(true);
    grid->attach(*space, 0, 1, 1, 1);
    Gtk::Label *total = Gtk::manage(new Gtk::Label{"Total"});
    grid->attach(*total, 0, 1, 1, 1);
    grid->attach(*totalAmount, 2, 1, 2, 1);
    Gtk::Label *bet = Gtk::manage(new Gtk::Label{"Bet Amount"});
    grid->attach(*bet, 0, 2, 1, 1);
    grid->attach(*betAmount, 2, 2, 2, 1);
    hbox2->pack_start(*grid);
    Gtk::Button *leaveButton = Gtk::manage(new Gtk::Button{"Leave"});
    hbox2->pack_start(*leaveButton);
    leaveButton->signal_clicked().connect([this] {this->on_leave_click();});

    vbox->show_all();
}

Mainwin::~Mainwin() { }


/// Callback to methods
    void Mainwin::on_bet_click() {
    Gtk::Dialog dialog{"Betting window", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"How much will you bet"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Place Bet", 1);
    dialog.add_button("Cancel Bet", 0);

    dialog.show_all();
    dialog.run();
    betAmount->set_text("$" + e_name.get_text());
    }


    void Mainwin::on_check_click() {
    betAmount->set_text("$0");
    }   

     
    void Mainwin::on_fold_click() {
    }     
                
    void Mainwin::on_swap_click() {
    Gtk::Dialog dialog{"Swap Decision", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Which Cards do you wish to swap"};
    Gtk::Label directions{"Please type numbers corresponding to cards with spaces in between, or type 'all'"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(directions, 0, 1, 2, 1);
    grid.attach(e_name, 0, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Swap", 1);
    dialog.add_button("Cancel Swap", 0);

    dialog.show_all();
    dialog.run();
    }   


    void Mainwin::on_leave_click() {
    close();
    }


