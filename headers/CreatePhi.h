if(kplus.size()>=1 && kminus.size()>=1){
     for(unsigned int i=0;i<kplus.size();i++){
     for(unsigned int j=0;j<kminus.size();j++){
        Particle phi = kplus[i] + kminus[j];
        Float_t m = phi.M();
        onlyaphi->Fill(m); 
        if(m<1.0 || m>1.05) continue;
        phi.ide1 = i; // K+
        phi.ide2 = j; // K-
        double kpd0,kmd0,kpz0,kmz0;
        kpd0 = kplus[i].d0;
        kmd0 = kminus[j].d0;
        kpz0 = kplus[i].z0;
        kmz0 = kminus[j].z0;
             //Filling hd0s
             hd0s->Fill(kpd0);
             hd0s->Fill(kmd0);
             //Filling hz0s
             hz0s->Fill(kpz0);
             hz0s->Fill(kmz0);
        if(MonteCarlo)
        {
           //check if phi is signal
           bool signalphi = kplus[i].m1id == 90 && kminus[j].m1id == 90 &&
                           kplus[i].m1brc == kminus[j].m1brc && kplus[i].id==11 && kminus[j].id==12;
           if(signalphi){ 
             phi.signal = true;
             phi.m1id = kplus[i].m2id;
             phi.m1brc = kplus[i].m2brc;
           //Filling hd0s
             hd0s2->Fill(kpd0);
             hd0s2->Fill(kmd0);
           //Filling hz0s
             hz0s2->Fill(kpz0);
             hz0s2->Fill(kmz0);  
             onlysphi->Fill(m);
           }
           else{
             phi.signal = false;       
             onlybphi->Fill(m); 
           }
        }

        Phi.push_back(phi);
     }
     }
}




