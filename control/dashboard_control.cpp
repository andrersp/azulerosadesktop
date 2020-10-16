#include "control/dashboard_control.h"

DashBoardControl::DashBoardControl(QWidget *parent) : DashBoardView(parent){

	info_client->set_value("25");
	
}
DashBoardControl::~DashBoardControl(){}