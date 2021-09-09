              //Filling momentum histogram of K+ & K- for background case 
               hpkpmb->Fill(pkaonp);
               hpkpmb->Fill(pkaonm);
	       hmphib->Fill(mph);
               Double_t anglePhiPib = (Phitvect.Angle(Piontvect))*180/M_PI;
               haPhiPib->Fill(anglePhiPib);
               hpPhib->Fill(pphi);
               hpPib->Fill(pPion);
             //Filling momentum histogram of Ds for background case
               hpdsb->Fill(pDs);   
             //Filling histogram of angle for K+- on background case
               haKpKmb->Fill(angleKpKm);
             //Filling histogram of difference between energy of K+ and K- for background
               hedKpKmb->Fill(diffe);
             //Filling histogram of sum between K+ and K- for background 
               hesKpKmb->Fill(sumekpkm);
             //Filling histogram of [abs((EK+) - (EK-))/((EK+) + (EK-))] for background
               hedpsKpKmb->Fill(diffeps);
             //Filling histogram of mass of Ds for background case
               hmdsb->Fill(mds);
              if(eDs >= 0.0 && eDs <= 9.0)
              {
                hmdsb09->Fill(mds);
              }
              else if(eDs > 9.0 && eDs <= 18.0)
              {
                hmdsb918->Fill(mds);
              }
              else if(eDs > 18.0 && eDs <= 27.0)
              {
                hmdsb1827->Fill(mds);
              }
              else if(eDs > 27.0 && eDs <= 36.0)
              {
                hmdsb2736->Fill(mds);
              }
              else if(eDs > 36.0 && eDs <= 45.6)
              {
                hmdsb3645->Fill(mds);
              }

             //Filling energy histogram for K+ and K- for background case
               heKpKmb->Fill(energykp);
               heKpKmb->Fill(energykm);
             //Filling energy histogram for Pion for background case
               hepionb->Fill(energypion);
             //Filling energy histogram for Phi for background case
               hephib->Fill(energyphi);   
             //Filling energy of Ds for background
               hedsb->Fill(eDs);
             //Filling histogram of energy difference between Phi and Pi for background
               hedPhiPib->Fill(diffePhiPi);
             //Filling energy difference per energy sum between Phi and Pi for background
               hedpsPhiPib->Fill(diffepsPhiPi);
             //Filling momentum difference per momentum sum (in fabs) of K+- for background
               hpdpskb->Fill(pdiffpsumk);
             //Filling momentum difference per momentum sum (in fabs) of Phi&Pi for background
               hpdpspb->Fill(pdiffpsumpp);
             //Filling energy of Ds per energy of K+ for background
               hedspekpb->Fill(edsperekp);
	      //Filling histogram of Eds/Ephi for background
               hedspephib->Fill(edsperephi); 
	      //Filling histogram of angle between K+- and Phi for background
               haPhiKpb->Fill(anglePhiKp);
               haPhiKmb->Fill(anglePhiKm);
              //Filling histogram of angle between K+- and Pi for background 
               haPiKpb->Fill(anglePiKp);
               haPiKmb->Fill(anglePiKm);			 

              //Fill K+ d0
               Float_t d0kp   = kplus[Phi[ph].ide1].d0;
               hd0kpb->Fill(d0kp);
             //Fill K+ z0
               Float_t z0kp   = kplus[Phi[ph].ide1].z0;
               hz0kpb->Fill(z0kp);
             //Fill K+ dedxkaon
               Float_t dedxkp = kplus[Phi[ph].ide1].dedxkaon;
               hdedxkpb->Fill(dedxkp);       
            //Fill K- d0
               Float_t d0km    = kminus[Phi[ph].ide2].d0;
               hd0kmb->Fill(d0km);
            //Fill K- z0 
               Float_t z0km   = kminus[Phi[ph].ide2].z0;
               hz0kmb->Fill(z0km); 
            //Fill K- dedxkaon
               Float_t dedxkm = kminus[Phi[ph].ide2].dedxkaon;
               hdedxkmb->Fill(dedxkm);
             //Fill Pion's d0
               Float_t d0pi = Pion[p].d0;
               hd0pib->Fill(d0pi);
            //Fill Pion's z0
               Float_t z0pi = Pion[p].z0;
               hz0pib->Fill(z0pi); 													     
	    //Fill Pion's dedxpion
               Float_t dedxpi = Pion[p].dedxpion;
               hdedxpib->Fill(dedxpi);       												     
            //Filling TNtuple for AI bkg 
               tmvadataB->Fill(anglePhiPi,angleKpKm,eDs,sumekpkm,anglePhiKp,anglePhiKm,anglePiKp,anglePiKm);
              

