$fn = 250;

//Adapter fuer Motorwelle PAN
difference(){
translate([-200,0,1]){cube([25,10,2], center=true);}
translate([-200,8,1]){
    rotate([0,0,10]){cube([40,10,3], center=true);}}
translate([-200,-8,1]){
    rotate([0,0,-10]){cube([40,10,3], center=true);}}
translate([-191,0,1]){cylinder(12,2.5,2.5,true);}}
translate([-202,0,4.5]){cylinder(5.5,2.3,2.5,true);}
//----------------------------------------------------------
//Adapter fuer Motorwelle TILT
difference(){
translate([-200,30,1]){cube([25,10,2], center=true);}
translate([-200,38,1]){ rotate([0,0,10]){
    cube([40,10,3], center=true);}}
translate([-200,22,1]){ rotate([0,0,-10]){
    cube([40,10,3], center=true);}}
translate([-180.5,38,1]){ rotate([0,0,35]){
    cube([20,10,3], center=true);}}
translate([-180.5,22,1]){ rotate([0,0,-35]){
    cube([20,10,3], center=true);}}
translate([-191,30,1]){cylinder(12,2.5,2.5,true);}
translate([-210,30,1]){cube([10,10,3], center=true);}
}
translate([-202,30,4.5]){cylinder(5.5,2.3,2.5,true);}
//----------------------------------------------------------
//Verbindungsstange PAN
//TODO: Radien nach Spiel einstellen!!!
difference(){
translate([-140,0,0]){cube([8,120,4], center=true);}
translate([-140,55,0]){cylinder(20,2.5,2.6,center=true);}
translate([-140,-55,0]){cylinder(20,2.5,3.8,center=true);}
translate([-140,-55,0]){cylinder(20,3.8,2.5,center=true);}
}
//-----------------------------------------------------------
//Verbindungsstange TILT
//TODO: Radien nach Spiel einstellen!!!
difference(){
translate([-160,0,0]){cube([8,40,2], center=true);}
translate([-160,16,0]){cylinder(20,2.5,2.6,center=true);}
translate([-160,-18,0]){cylinder(10,1.2,1.7,center=true);}
translate([-160,-18,0]){cylinder(10,1.7,1.2,center=true);}
translate([-166.5,-21,0]){    rotate([0,0,-55]){
    cube([10,10,3],center=true);}}
translate([-153.5,-21,0]){    rotate([0,0,55]){
    cube([10,10,3],center=true);}}
translate([-201,0,0]){cylinder(10,40,40,center=true);}
translate([-119,0,0]){cylinder(10,40,40,center=true);}
}