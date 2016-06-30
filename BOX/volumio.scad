
module fillet(r, h) {
        difference() {
            cube([r + 0.01, r + 0.01, h], center = true);
            translate([r/2, r/2, 0])
                cylinder(r = r, h = h + 1, $fn = 200,center = true);
        }
}

module torreta(h){
    translate([0,0 , h/2-.2 ])difference(){
  cylinder(  h-1.5 , 2.5,  2.5 ,true); 
  cylinder(  h , 1,  1.7 ,true);  
}
}

module soporte_pi (){
    
	translate([29, 25, 0])  torreta(9); 
	translate([-29, -25,  0 ])  torreta(9);  
	translate([-29, 25,  0])  torreta(9); 
	translate([29, -25,  0 ])  torreta(9);  
    
}
module torreta_puls(){
   	rotate([270,0,0]) translate([14, 0, 0])  torreta(7); 
	rotate([270,0,0]) translate([-14, 0,  0 ])  torreta(7);   
    
}

module soporte_usb (){
  translate([8, 0, 0 ])  torreta(3);
  translate([-8, 0, 0 ])  torreta(3);
}



module perfil(li,wi,h,t,r,tip){
    le=li+t*2;
    we=wi+t*2;
    
    module round(p){
        if (p==0){
        translate ([le/2-5,   we/2-5 ,0])rotate([180,180,0])fillet(r, h+1);
        translate ([(le/2*-1)+5,we/2-5,0])rotate([180,0,0])fillet(r, h+1);
        translate ([le/2-5,   (we/2*-1)+5,0])rotate([0,180,0])fillet(r, h+1);
        translate ([(le/2*-1)+5,(we/2*-1)+5,0])rotate([0,0,0])fillet(r, h+1);
        }
        else{     
        translate ([li/2-5,   wi/2-5 ,0])rotate([180,180,0])fillet(r, h+1);
        translate ([(li/2*-1)+5,wi/2-5,0])rotate([180,0,0])fillet(r, h+1);
        translate ([li/2-5,   (wi/2*-1)+5,0])rotate([0,180,0])fillet(r, h+1);
        translate ([(li/2*-1)+5,(wi/2*-1)+5,0])rotate([0,0,0])fillet(r, h+1);    
        }

}

    difference(){
    difference(){
    cube([le , we, h ] ,true );
    round(0);
    }
    if (tip!=1){
    difference(){
    cube([li , wi, h+1 ] ,true );
        round(1);
        }
    }
    }
}

module sop_pul(){
    difference(){
    cube([38,1.6,,20], center = true);  
     cube([15.5, 5,15.5  ] ,true );  
        }
     translate([0, -6.5, 0 ])torreta_puls();
    }

//tapa inferior
module tapa_i(){
  
 perfil(90,76,1.6,1.6,10,1);

 difference(){
 translate([0,0,4])perfil(90,76,8,1.6,10,0);
 translate([0, -40, 6 ])  cube([9,9,7], center = true);   
   rotate([0,90,0])  translate([-4,28,0]) cylinder(  105 , 2,  2 ,true, $fn=100); 
  rotate([0,90,0])  translate([-4,-28,0]) cylinder(  105 , 2,  2 ,true, $fn=100); 
      translate([ -15.5,38,11]) cube([18, 5,16 ] ,true ); 
     translate([ -48,-5,6]) cube([7, 20,5 ] ,true ); 
     }

 translate([-10.5, -7.5, 0])   soporte_pi ();
 translate([0, -35, 0 ])   soporte_usb();

   translate([-15.1, 38.8, 13. ]) sop_pul(); ;
}

// tapa superior
module tapa_s(){
    difference(){
 perfil(94.5,80.4,39,1.6,10,0);
  translate([0, -40, -11 ])  cube([9,9,7], center = true); 
  translate([47,-7,1]) cube([7,55,20], center = true);     
//pulsador
translate([-15,40,-4])    cube([15.5, 5,15.5  ] ,true );  
//sd      
 translate([ -48,-5,-11]) cube([7, 20,5 ] ,true );

// rear
translate([ 0,-40,1.5]) cube([38, 7,28 ] ,true );        
    }  
    

    
 translate([0,0,19]) perfil(94.5,80.5,1.6,1.6,10,1);
 rotate([0,90,0])  translate([13,28,47]) cylinder(  3 , 1.8,  1.8 ,true, $fn=100); 
 rotate([0,90,0])  translate([13,-28,47]) cylinder(  3 , 1.8,  1.8 ,true, $fn=100);
 rotate([0,90,0])  translate([13,28,-47]) cylinder(  3 , 1.8,  1.8 ,true, $fn=100); 
 rotate([0,90,0])  translate([13,-28,-47]) cylinder(  3 , 1.8,  1.8 ,true, $fn=100);
    
  
   
}
color("LimeGreen")tapa_i();
//translate([0,0,19])tapa_s(); //z:19 / 35


