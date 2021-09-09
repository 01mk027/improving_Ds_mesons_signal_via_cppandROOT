    for(unsigned int i=0; i<Trk->trk_px->size(); i++){
      //check if truthindex is negative or exceeds the size
      unsigned int truthindex = 0;
      if(MonteCarlo){
        truthindex = Trk->trk_truthindex->at(i);
        if(truthindex < 0) continue;
        if(truthindex >= Tru->tru_m1id->size()) continue;
      }

      //define temporary particle, set mass, and truth informations
      Particle kp, km, pion; 
      kp.SetXYZM(Trk->trk_px->at(i),Trk->trk_py->at(i),Trk->trk_pz->at(i),0.4937);
      km.SetXYZM(Trk->trk_px->at(i),Trk->trk_py->at(i),Trk->trk_pz->at(i),0.4937);
      pion.SetXYZM(Trk->trk_px->at(i),Trk->trk_py->at(i),Trk->trk_pz->at(i),0.1395);
          kp.d0       = Trk->trk_d0->at(i);
          kp.z0       = Trk->trk_z0->at(i);
          kp.dedxkaon = Trk->trk_dedxkaon->at(i);
          km.d0       = Trk->trk_d0->at(i);
          km.z0       = Trk->trk_z0->at(i);
          km.dedxkaon = Trk->trk_dedxkaon->at(i);
          pion.d0       = Trk->trk_d0->at(i);
          pion.z0       = Trk->trk_z0->at(i);
          pion.dedxpion = Trk->trk_dedxpion->at(i);
      //track momentum cut 5 GeV 
      if(Tru->tru_id->at(truthindex) == 11 || Tru->tru_id->at(truthindex) == 12)
      {
        if(Trk->trk_dedxkaon->at(i) == 0) continue;
        hdedxKall->Fill(Trk->trk_dedxkaon->at(i));
      }
      if(Tru->tru_id->at(truthindex) == 8 || Tru->tru_id->at(truthindex) == 9)
      {
        if(Trk->trk_dedxpion->at(i) == 0) continue;
        hdedxapi->Fill(Trk->trk_dedxpion->at(i));
      }
      if(kp.P() > 1.0 && km.P()> 1.0)
      {
       //fill d0 & z0 for all K+-
 //     hd0akp->Fill(kp.d0);
 //     hz0akp->Fill(kp.z0);
 //     hd0akm->Fill(km.d0);
 //     hz0akm->Fill(km.z0);
      double kpd0,kpz0,kmd0,kmz0;
      kpd0 = kp.d0;
      kmd0 = km.d0;
      kpz0 = kp.z0;
      kmz0 = km.z0;
      hd0a  ->Fill(kpd0);
      hd0a  ->Fill(kmd0);
      hz0a  ->Fill(kpz0);
      hz0a  ->Fill(kmz0);
      hdedxa->Fill(kp.dedxkaon);
      hdedxa->Fill(km.dedxkaon);
      hdedxakp->Fill(kp.dedxkaon);
      hdedxakm->Fill(km.dedxkaon);
  
  /*      if(kp.id == 11)
          hdedxKall->Fill(kp.dedxkaon);
        if(km.id == 12)
          hdedxKall->Fill(km.dedxkaon);      
*/
       //fill d0 & z0 histograms 
      if(fabs(kp.d0) > 0.5 && fabs(km.d0) > 0.5) continue;   
        if(fabs(kp.z0) > 2.0 && fabs(km.z0) > 2.0)  continue;
          if(fabs(kp.dedxkaon) > 3.0 && fabs(km.dedxkaon) > 3.0)  continue;
//{ continue;;
            if(MonteCarlo){
                kp.id    = Tru->tru_id->at(truthindex);
                kp.m1id  = Tru->tru_m1id->at(truthindex);
                kp.m1brc = Tru->tru_m1brc->at(truthindex);
                km.id    = Tru->tru_id->at(truthindex);
                km.m1id  = Tru->tru_m1id->at(truthindex);
                km.m1brc = Tru->tru_m1brc->at(truthindex);
                kp.m2id  = Tru->tru_m2id->at(truthindex);
                kp.m2brc = Tru->tru_m2brc->at(truthindex);
                km.m2id  = Tru->tru_m2id->at(truthindex);
                km.m2brc = Tru->tru_m2brc->at(truthindex);
                          }
           
        //fill kplus and kminus vector
        if(Trk->trk_ch->at(i)==1) kplus.push_back(kp);
        else                      kminus.push_back(km);     
              } 
      // pion track momentum cut

      if(pion.P()>0.5)
      {
      //fill d0 & z0 for all pion
//      hd0api->Fill(pion.d0);
//      hz0api->Fill(pion.z0);
      double piond0;
      piond0 = pion.d0;
      hd0a  ->Fill(piond0);
      hz0a  ->Fill(pion.z0);
      hdedxa->Fill(pion.dedxpion);
        if(pion.d0 > fabs(0.5)) continue; // { continue;
          if(pion.z0 > fabs(2.0)) continue; //{continue;
            if(fabs(pion.dedxpion) > 3.0) continue;
                    if(MonteCarlo){
                    pion.id    = Tru->tru_id->at(truthindex);
                    pion.m1id  = Tru->tru_m1id->at(truthindex);
                    pion.m1brc = Tru->tru_m1brc->at(truthindex);
                                  }  
        pion.ch = Trk->trk_ch->at(i);
        Pion.push_back(pion);
                                          //}
                                // }          
                               //}
      }
    
}//for-loop's closing bracelet



