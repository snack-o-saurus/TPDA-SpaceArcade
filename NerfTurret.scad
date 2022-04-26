$fn=200; //Auflösung

//Erstellen der Grundplatte mit Nut
union(){    difference(){
cube([200,180,40], center=true);
//Aussparung für PAN-Servomotor 
 translate([60,60,0]){cube([29,29,45], center=true);} 
 translate([60,85,-22]){cube([5,25,10], center=true);}
 
 //Nut
 translate([0,0,37]){    
  difference(){   
    cylinder(h=40,r=50, center=true);
    cylinder(h=40,r=45, center=true); }}}
    
translate([44.5,60,22]){cube([2,30,5], center=true); } 
translate([75.5,60,22]){cube([2,30,5], center=true); } 
//Top plate for engine screwdown       
difference(){  
 translate([60,60,25]){cube([33,30,2], center=true);}  
    // 1/1000 clearance for engine shaft 
 translate([60,60,25]){cylinder(5, 2.6, center=true);}
    //Screwdown points
 translate([50,70,25]){cylinder(5, 2.5, center=true);}
 translate([70,70,25]){cylinder(5, 2.5, center=true);}
 translate([70,50,25]){cylinder(5, 2.5, center=true);}
 translate([50,50,25]){cylinder(5, 2.5, center=true);}
 }
}
//------------------------------------------------------------
 //Turmteil inkls Feder für Grundplatte
 translate([200,0,105]){
 cylinder(180, 65, 50, center=true); }
 translate([200,0,16]){     difference(){   
    cylinder(h=10,r=50, center=true);
    cylinder(h=10.5,r=45, center=true);}}
//Servo-Anbindung PAN
 translate([123,0,35]){cube([30,14,8], center=true); }
 translate([118,0,31]){cylinder(5,3.5,3,center=true);}
 //Turret für TILT-Aufnahme der Nerf
 difference(){
 translate([180,0,210]){ rotate([0,90,0]){
     cylinder(60, 50, 50, center=true);}}
 //Bohrung fuer 10mm-Verbindungsstift
 translate([170,17.5,228]){ rotate([0,90,0]){
   cylinder(50, 5, 5, center=true);} }
 translate([166,-25,225]){
     cube([33,29,29],center=true);}
 translate([178,-25,225]){  rotate([0,90,0]){
     cylinder(25,2.5,2.5,center=true);}}
 translate([199,-20,238]){rotate([-40,0,0]){
     cube([30,38,104],center=true);}}
 translate([199,-15,230]){rotate([-75,0,0]){
     cube([30,38,120],center=true);}}
 }
 difference(){
translate([230,0,210]){ rotate([0,90,0]){
   cylinder(40, 50, 50, center=true);}}
translate([230,17.5,228]){ rotate([0,90,0]){
   cylinder(50, 5, 5, center=true);}}
  }  
//-----------------------------------------------------------
//10mm - TILT - Verbindungsstift
translate([200,-150,5]){ rotate([0,90,0]){
  cylinder(100,5,5,center=true);  
}}
//-----------------------------------------------------------
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
translate([-191,0,0]){cylinder(10,30,30,center=true);}
translate([-129,0,0]){cylinder(10,30,30,center=true);}
}
//----------------------------------------------------------
//Halterung NERF
translate([400,0,10]){ rotate([0,90,0]){
 difference(){  cylinder(10,6,6,center=true);  
                cylinder(11,5,5,center=true);}}}
//VL
difference(){
translate([389,13,50]){ rotate([-15,-15,0]){
  cylinder(77,2.5,2.5,center=true);}}
translate([400,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//VR
 difference(){
translate([411,13,50]){ rotate([-15,15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([400,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//HL
 difference(){
translate([389,-13,50]){ rotate([15,-15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([400,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//HR
 difference(){
translate([411,-13,50]){ rotate([15,15,0]){
    cylinder(77,2.5,2.5,center=true);}}
translate([400,0,10]){ rotate([0,90,0]){
 cylinder(11,5,5,center=true);}}}
//-- SEC R -- >>SCREW HOLE ID: 2,5mm
difference(){
translate([420,0,85]){  rotate([90,0,0]){
   cylinder(140,4,4,center=true);}}
translate([420,-60,85]){  rotate([90,0,0]){
   cylinder(25,2.5,2.5,center=true);}}}
//LOWER RIGHT
translate([411,4,50]){ rotate([-45,15,0]){
  cylinder(36,2.5,2.5,center=true);}}
translate([414,-5,62]){ rotate([32,15,0]){
  cylinder(55,2.5,2.5,center=true);}}
//-- SEC L -- >>SCREW HOLE ID: 2,5mm
difference(){
 translate([380,0,85]){  rotate([90,0,0]){
   cylinder(140,4,4,center=true);}}
 translate([380,-60,85]){  rotate([90,0,0]){
   cylinder(25,2.5,2.5,center=true);}}}
//LOWER LEFT
translate([389,4,50]){ rotate([-45,-15,0]){
  cylinder(36,2.5,2.5,center=true);}}
translate([386,-5,62]){ rotate([32,-15,0]){
  cylinder(55,2.5,2.5,center=true);}}
//-- FRAME FRONT: STRUTS --
translate([400,17.25,65]){  rotate([0,90,0]){
   cylinder(32,2.5,2.5,center=true);}}
translate([400,26,85]){  rotate([0,90,0]){
   cylinder(40,3,3,center=true);}}
translate([400,46,85]){  rotate([45,90,0]){
   cylinder(60,3,3,center=true);}}
translate([400,46,85]){  rotate([-45,90,0]){
   cylinder(60,3,3,center=true);}}
translate([400,67,85]){  rotate([0,90,0]){
   cylinder(44,4,4,center=true);}}
//FRONT TIEDOWNS #1
translate([386,55,100]){  rotate([-45,25,0]){
   cylinder(40,2,2,center=true);}}
translate([414,55,100]){  rotate([-45,-25,0]){
   cylinder(40,2,2,center=true);}}
translate([400,68,112]){  rotate([0,90,0]){
   cylinder(20,2,2,center=true);}}
//FT #2
translate([386,45,100]){  rotate([-45,25,0]){
   cylinder(40,2,2,center=true);}}
translate([414,45,100]){  rotate([-45,-25,0]){
   cylinder(40,2,2,center=true);}}
translate([400,58,112]){  rotate([0,90,0]){
   cylinder(20,2,2,center=true);}}   
//FRAME BACK TILT CONNECTOR >> PIN CONNECTOR ID: ~3mm
translate([400,-9.5,38]){  rotate([0,90,0]){
   cylinder(19,2.5,2.5,center=true);}}
difference(){
translate([400,-7,31]){   rotate([108,0,0]){
    cube([4,20,6],center=true);}}
translate([398,-8,28]){   rotate([108,0,0]){
    cube([4,10,6],center=true);}}}
difference(){
translate([401,-11,26]){   rotate([108,0,0]){
    cube([2,13,6],center=true);}}
translate([401,-16,30]){   rotate([75,0,0]){
    cube([4,12,6],center=true);}}
translate([401,-10,18]){   rotate([170,0,0]){
    cube([4,12,6],center=true);}}}
translate([399,-11,27]){  rotate([0,90,0]){
   cylinder(2.5,1.6,1.25,center=true);}}
