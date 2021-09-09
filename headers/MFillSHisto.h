             //Filling momentum histogram of K+ & K- for signal case 
               hpkpms->Fill(pkaonp);
               hpkpms->Fill(pkaonm);
             //Filling histogram of mass of Phi for signal case
               hmphis->Fill(mph);  
             //Filling momentum histogram of Phi for signal case
               hpPhis->Fill(pphi);
             //Filling momentum histogram of Pion for signal case       
               hpPis->Fill(pPion);
             //Filling histogram of mass of Ds for signal case
               hmdss->Fill(mds);
               if(eDs >= 0.0 && eDs <= 9.0)
               {
                 hmdss09->Fill(mds);
               }
               else if(eDs > 9.0 && eDs <= 18.0)
               {
                 hmdss918->Fill(mds);
               }
               else if(eDs > 18.0 && eDs <= 27.0)
               {
                 hmdss1827->Fill(mds);
               }
               else if(eDs > 27.0 && eDs <= 36.0)
               {
                 hmdss2736->Fill(mds);
               }
               else if(eDs > 36.0 && eDs <= 45.6)
               {
                 hmdss3645->Fill(mds);
               }

             //Filling histogram of angle between Phi and Pion+- for signal
               haPhiPis->Fill(anglePhiPi);           
             //Filling histogram of angle between K+ and K- for signal      
       	       haKpKms->Fill(angleKpKm);
             //Filling histogram of difference between energy of K+ and K- for signal
               hedKpKms->Fill(diffe);  
             //Filling histogram of sum between K+ and K- for signal   
               hesKpKms->Fill(sumekpkm);
             //Filling histogram of [abs((EK+) - (EK-))/((EK+) + (EK-))] for signal
               hedpsKpKms->Fill(diffeps);
             //Filling energy histogram for K+ and K- for signal case
               heKpKms->Fill(energykp);
               heKpKms->Fill(energykm);
             //Filling energy histogram of Pion for signal case
               hepions->Fill(energypion);
             //Filling energy histogram of Phi for signal case
               hephis->Fill(energyphi);
             //Filling momentum histogram of Ds for signal case
               hpdss->Fill(pDs);   
             //Filling energy of Ds for signal
               hedss->Fill(eDs);   
             //Filling histogram of energy difference between Phi and Pi for signal
               hedPhiPis->Fill(diffePhiPi);
             //Filling energy difference per energy sum between Phi and Pi for signal  
               hedpsPhiPis->Fill(diffepsPhiPi);
             //Filling momentum difference per momentum sum (in fabs) of K+- for signal
               hpdpsks->Fill(pdiffpsumk);
             //Filling momentum difference per momentum sum (in fabs) of Phi&Pi for signal
               hpdpsps->Fill(pdiffpsumpp);
             //Filling energy of Ds per energy of K+ for signal
               hedspekps->Fill(edsperekp);
             //Filling angle between K+- and Phi for signal
               haPhiKps->Fill(anglePhiKp);
               haPhiKms->Fill(anglePhiKm);			 
              //Filling histogram of angle between K+- and Pi for signal 
               haPiKps->Fill(anglePiKp);			 
               haPiKms->Fill(anglePiKm);			 
 	     //Fill d0 of D_s for signal
               //hd0s->Fill(kplus[Phi[ph].ide1].d0);
               //hd0s->Fill(kminus[Phi[ph].ide2].d0);
               //hd0s->Fill(Pion[p].d0);
	     //Fill z0 of D_s for signal
               //hz0s->Fill(kplus[Phi[ph].ide1].z0);
               //hz0s->Fill(kminus[Phi[ph].ide2].z0);
               //hz0s->Fill(Pion[p].z0);
             //Fill K+ d0
               Float_t d0kp   = kplus[Phi[ph].ide1].d0;
               hd0kps->Fill(d0kp);
             //Fill K+ z0
               Float_t z0kp   = kplus[Phi[ph].ide1].z0;
               hz0kps->Fill(z0kp);
             //Fill K+ dedxkaon
               Float_t dedxkp = kplus[Phi[ph].ide1].dedxkaon;
               hdedxkps->Fill(dedxkp);       
             //Fill K- d0
               Float_t d0km    = kminus[Phi[ph].ide2].d0;
               hd0kms->Fill(d0km);
             //Fill K- z0 
               Float_t z0km   = kminus[Phi[ph].ide2].z0;
               hz0kms->Fill(z0km); 
             //Fill K- dedxkaon
               Float_t dedxkm = kminus[Phi[ph].ide2].dedxkaon;
               hdedxkms->Fill(dedxkm);
             //Fill Pion's d0
               Float_t d0pi = Pion[p].d0;
               hd0pis->Fill(d0pi);
             //Fill Pion's z0
                Float_t z0pi = Pion[p].z0;
                hz0pis->Fill(z0pi); 													     
	     //Fill Pion's dedxpion
               Float_t dedxpi = Pion[p].dedxpion;
               hdedxpis->Fill(dedxpi);       												     
             //Filling histogram of Eds/Ephi for signal
               hedspephis->Fill(edsperephi);
             //Filling dedxs's
               hdedxs->Fill(kplus[Phi[ph].ide1].dedxkaon);
               hdedxs->Fill(kminus[Phi[ph].ide2].dedxkaon);
               hdedxs->Fill(Pion[p].dedxpion);
             //Filling TNtuple for AI sgn  
               tmvadataS->Fill(anglePhiPi,angleKpKm,eDs,sumekpkm,anglePhiKp,anglePhiKm,anglePiKp,anglePiKm);


