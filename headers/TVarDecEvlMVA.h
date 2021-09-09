  angleKpKm = (kplustvect.Angle(kminustvect))*180/M_PI;
  anglePhiPi = (Phitvect.Angle(Piontvect))*180/M_PI;
  eDs = Dsp.E();
  sumekpkm = kplus[Phi[ph].ide1].E()+kminus[Phi[ph].ide2].E();
  anglePhiKp = (kplustvect.Angle(Phitvect))*180/M_PI;
  anglePhiKm = (kminustvect.Angle(Phitvect))*180/M_PI;
  anglePiKp = (kplustvect.Angle(Piontvect))*180/M_PI;
  anglePiKm = (kminustvect.Angle(Piontvect))*180/M_PI; 
            double estimator = reader->EvaluateMVA(methodName);
            bool estcut = estimator > tmvacut;
               /////kplus[ Phi[ph].ide1 ]   +  BURA OK ... 
               /////kminus[ Phi[ph].ide2 ]  -

