//Setting TVector3 of K- and K+'s X,Y and Z Component
            kplustvect.SetX(kplus[Phi[ph].ide1].Px());
            kplustvect.SetY(kplus[Phi[ph].ide1].Py()); 
            kplustvect.SetZ(kplus[Phi[ph].ide1].Pz());
            kminustvect.SetX(kminus[Phi[ph].ide2].Px());
            kminustvect.SetY(kminus[Phi[ph].ide2].Py());
            kminustvect.SetZ(kminus[Phi[ph].ide2].Pz());
        //Setting TVector3 of Pion+-'s X,Y and Z Component
            Piontvect.SetX(Pion[p].Px());
            Piontvect.SetY(Pion[p].Py());
            Piontvect.SetZ(Pion[p].Pz());
        //Setting TVector3 of Phi's X,Y and Z Component        
            Phitvect.SetX(Phi[ph].Px());
            Phitvect.SetY(Phi[ph].Py());
            Phitvect.SetZ(Phi[ph].Pz());
