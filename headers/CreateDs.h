    for(unsigned int ph=0;ph<Phi.size();ph++){
        for(unsigned int p=0;p<Pion.size();p++){
            Particle Dsp = Phi[ph] + Pion[p];
            Float_t mds = Dsp.M();
            if(mds<1.8 || mds>2.1) continue;
            
            #include "SetTVect.h" 
            Float_t angleKpKm = (kplustvect.Angle(kminustvect))*180/M_PI;
            Float_t anglePhiPi = (Phitvect.Angle(Piontvect))*180/M_PI;
            Float_t eDs = Dsp.E();
            Float_t sumekpkm = kplus[Phi[ph].ide1].E()+kminus[Phi[ph].ide2].E();
            Float_t anglePhiKp = (kplustvect.Angle(Phitvect))*180/M_PI;
            Float_t anglePhiKm = (kminustvect.Angle(Phitvect))*180/M_PI;
            Float_t anglePiKp = (kplustvect.Angle(Piontvect))*180/M_PI;
            Float_t anglePiKm = (kminustvect.Angle(Piontvect))*180/M_PI;
//           Double_t d0kp   = kplus[Phi[ph].ide1].d0;
//           Double_t z0kp   = kplus[Phi[ph].ide1].z0;
//           Double_t dedxkp = kplus[Phi[ph].ide1].dedxkaon;
//           Double_t d0km   = kminus[Phi[ph].ide2].d0;
//           Double_t z0km   = kminus[Phi[ph].ide2].z0;
//           Double_t dedxkm = kplus[Phi[ph].ide2].dedxkaon;
//           Double_t dedxpi = Pion[p].dedxpion;
            #include "MFillAHisto.h"
            bool signaldsp = ((Phi[ph].m1id == 39 && Pion[p].m1id == 39 && Pion[p].id==8) || (Phi[ph].m1id == 40 && Pion[p].m1id == 40 && Pion[p].id==9)) && Phi[ph].m1brc == Pion[p].m1brc && Phi[ph].signal == true;
            if(signaldsp){
            #include "MFillSHisto.h" 
                         }
            else         {
            #include "MFillBHisto.h"           
                         } 
     }
     }

