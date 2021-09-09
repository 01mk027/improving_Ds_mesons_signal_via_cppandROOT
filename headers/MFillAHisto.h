            hmdsa->Fill(mds);
            if(eDs >= 0.0 && eDs <= 9.0)
            {
              hmdsa09->Fill(mds);
            }
            else if(eDs > 9.0 && eDs <= 18.0)
            {
              hmdsa918->Fill(mds);
            }
            else if(eDs > 18.0 && eDs <= 27.0)
            {
              hmdsa1827->Fill(mds);
            }
            else if(eDs > 27.0 && eDs <= 36.0)
            {
              hmdsa2736->Fill(mds);
            }
            else if(eDs > 36.0 && eDs <= 45.6)
            {
              hmdsa3645->Fill(mds);
            }

  


        //Setting angles between Phi and Pion+- for all
            haPhiPia->Fill(anglePhiPi);
        //Setting angle between K+ and K- for all        
	    haKpKma->Fill(angleKpKm);
         //Setting angle between K+ and Phi & filling hist. for all                    
	    haPhiKpa->Fill(anglePhiKp);            
            haPhiKma->Fill(anglePhiKm);          
        //Setting angle between K+- and Pi & filling hist. for all
            haPiKpa->Fill(anglePiKp); 
            haPiKma->Fill(anglePiKm);             
        //Setting momentum of Ds and filling momentum histogram for all case
            Float_t pDs = Dsp.P();
            hpdsa->Fill(pDs);
        //Setting difference of energy between K+ & K-  
            Float_t diffe = fabs(kplus[Phi[ph].ide1].E()-kminus[Phi[ph].ide2].E());
        //Setting energy difference per energy sum between K+ and K-    
            Float_t diffeps = abs(kplus[Phi[ph].ide1].E()-kminus[Phi[ph].ide2].E())/(kplus[Phi[ph].ide1].E()+kminus[Phi[ph].ide2].E());
        //Filling histogram of difference between energy of K+ and K- for all
            hedKpKma->Fill(diffe);
        //Filling histogram of sum of energy between K+ and K- for all   
            hesKpKma->Fill(sumekpkm);
        //Filling histogram of [((EK+) - (EK-))/((EK+) + (EK-))] for all
            hedpsKpKma->Fill(diffeps);//Between [0,1] 
        //Filling histogram of momentum for Phi on all case
            Float_t pphi = Phi[ph].P();
            hpPhia->Fill(pphi);
        //Filling histogram of momentum for Pion+- on all case 
            Float_t pPion = Pion[p].P();
            hpPia->Fill(pPion);
        /////kplus[ Phi[ph].ide1 ]   +  BURA OK ...
        /////kminus[ Phi[ph].ide2 ]  -
        //Filling energy histogram for K+ and K- for all case
            Float_t energykp = kplus[Phi[ph].ide1].E();
            Float_t energykm = kminus[Phi[ph].ide2].E();
            heKpKma->Fill(energykp);
            heKpKma->Fill(energykm);
        //Filling momentum histogram of K+ and K- for all case 
            Float_t pkaonp = kplus[ Phi[ph].ide1 ].P();     
            Float_t pkaonm = kminus[ Phi[ph].ide2 ].P();
            hpkpma->Fill(pkaonp);
            hpkpma->Fill(pkaonm);
        //Filling energy histogram for Pion for all case
            Float_t energypion = Pion[p].E();
            hepiona->Fill(energypion);
        //Filling energy histogram for Phi for all case
            Float_t energyphi = Phi[ph].E();
            hephia->Fill(energyphi);
        //Filling energy of Ds for all
            hedsa->Fill(eDs);   
        //Filling histogram of energy difference between Phi and Pi for all
            Float_t diffePhiPi = fabs(Phi[ph].E() - Pion[p].E());
            hedPhiPia->Fill(diffePhiPi);
        //Filling energy difference per energy sum between Phi and Phi    
            Float_t diffepsPhiPi = fabs((Phi[ph].E() - Pion[p].E()) / (Phi[ph].E() + Pion[p].E()));
            hedpsPhiPia->Fill(diffepsPhiPi); 
        //Setting momentum difference per momentum sum of K+- & filling for all
            Float_t pdiffpsumk = fabs((pkaonp - pkaonm) / (pkaonp+pkaonm));
            hpdpska->Fill(pdiffpsumk);
        //Filling momentum difference per momentum sum  of Phi and Pi for all case
            Float_t pdiffpsumpp = fabs((pphi-pPion) / (pphi+pPion));
            hpdpspa->Fill(pdiffpsumpp); 
        //Filling energy of ds per energy of K+ for all
            Float_t edsperekp = eDs / energykp ;
            hedspekpa->Fill(edsperekp);
        //Filling "energy of ds per energy of phi" histogram for all
            Float_t edsperephi = eDs / energyphi ;
            hedspephia->Fill(edsperephi);   
        //Fill mass of phi
            Float_t mph = Phi[ph].M();
            hmphia->Fill(mph);



        //Fill K+ d0
            Float_t d0kp   = kplus[Phi[ph].ide1].d0;
            hd0kpa->Fill(d0kp);
        //Fill K+ z0
            Float_t z0kp   = kplus[Phi[ph].ide1].z0;
            hz0kpa->Fill(z0kp);
        //Fill K+ dedxkaon
            Float_t dedxkp = kplus[Phi[ph].ide1].dedxkaon;
            hdedxkpa->Fill(dedxkp);       
        //Fill K- d0
            Float_t d0km    = kminus[Phi[ph].ide2].d0;
            hd0kma->Fill(d0km);
        //Fill K- z0 
            Float_t z0km   = kminus[Phi[ph].ide2].z0;
            hz0kma->Fill(z0km); 
        //Fill K- dedxkaon
            Float_t dedxkm = kminus[Phi[ph].ide2].dedxkaon;
            hdedxkma->Fill(dedxkm);
        //Fill Pion's d0
            Float_t d0pi = Pion[p].d0;
            hd0pia->Fill(d0pi);
        //Fill Pion's z0
            Float_t z0pi = Pion[p].z0;
            hz0pia->Fill(z0pi);
	//Fill Pion's dedxpion
            Float_t dedxpi = Pion[p].dedxpion;
            hdedxpia->Fill(dedxpi);       												     




