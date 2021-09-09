    for(unsigned int ph=0;ph<Phi.size();ph++){
        for(unsigned int p=0;p<Pion.size();p++){
            Particle Dsp = Phi[ph] + Pion[p];
            Float_t mds = Dsp.M();
            if(mds<1.8 || mds>2.1) continue;
            
            #include "headers/SetTVect.h"
            #include "headers/MFillAHisto.h"
        //check if ds+ signal
            bool signaldsp = ((Phi[ph].m1id == 39 && Pion[p].m1id == 39 && Pion[p].id==8) || (Phi[ph].m1id == 40 && Pion[p].m1id == 40 && Pion[p].id==9)) && Phi[ph].m1brc == Pion[p].m1brc && Phi[ph].signal == true;
            if(signaldsp)
                {
                 #include "headers/MFillSHisto.h"      
                }
            else
                {
                 #include "headers/MFillBHisto.h"
                } 
     }
     }

