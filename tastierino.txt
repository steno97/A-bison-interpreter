macchina a stati finiti della SCO del tastierino:

global variables{
}

events{
    status_on;
    status_off;
    int_req_0;
    return_sca;
}

commands{
    turn_on;
    set_int_req_1;
    set_int_req_0;
    set_status_1;
    set_status_0;
    print_schermo_message;
}

#accensione:  microprogramma della sco che parte all'avvio della periferica
#          e non può essere raggiunto in un secondo momento
#          viene preparata la sca e settati i flip-flop
state off{
    actions{set_status_0};
    =>prepeare_turned_on;
}

state prepeare_turned_on{
    actions{turn_on, set_int_req_0};
    =>turned on;
}

state turned_on{
    actions{set_status_1}; #nel caso in cui la cpu sia in busy waiting in attesa che la 
 			   #periferica si accenda, con questo comando comunichiamo alla
 			   #cpu che la periferica è pronta
    =>idle;
}

state idle{
    actions{set_status_0};
    status_on=>wait_return;
}

#insert
state wait_return{
    actions{set_status_0, start_sca}; 
    return_sca=>interrupt;
}

#interrupt
state interrupt{
    actions{set_status_1, set_int_req_1, set_iterator_0};
    status_off=>wait;
}

state wait{
    actions{set_int_req_0};
    status_on=>idle;
}

#gestione errore
state error{
    actions{print_schermo_message};
}

