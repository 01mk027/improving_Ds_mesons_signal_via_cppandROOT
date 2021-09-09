            hmdsa->Fill(m);
            if(estcut)
            {       
              if(eDs >= 0.0 && eDs <= 9.0)
              {
                hmdsa09->Fill(m);
              }
              else if(eDs > 9.0 && eDs <= 18.0)
              {
                hmdsa918->Fill(m);
              }
              else if(eDs > 18.0 && eDs <= 27.0)
              {
                hmdsa1827->Fill(m);
              }
              else if(eDs > 27.0 && eDs <= 36.0)
              {
                hmdsa2736->Fill(m);
              }
              else if(eDs > 36.0 && eDs <= 45.6)
              {
                hmdsa3645->Fill(m);
              }
            }  
           //Fill mass of Phi
            Float_t mph = Phi[ph].M();
            hmphia->Fill(mph);   
           //Fill d0 for each particle
            hd0kpa->Fill(kplus[Phi[ph].ide1].d0);
            hd0kma->Fill(kminus[Phi[ph].ide2].d0);
            hd0pia->Fill(Pion[p].d0);
           //Fill z0 for each particle
            hz0kpa->Fill(kplus[Phi[ph].ide1].z0);
            hz0kma->Fill(kminus[Phi[ph].ide2].z0);
            hz0pia->Fill(Pion[p].d0);
           //Fill dedx for each particle
            hdedxkpa->Fill(kplus[Phi[ph].ide1].dedxkaon);
            hdedxkma->Fill(kminus[Phi[ph].ide2].dedxkaon);
            hdedxpia->Fill(Pion[p].dedxpion);
            if(estcut)  hmdsEstCuta->Fill(m); 
           if(MonteCarlo)
           {
bool signaldsp = ((Phi[ph].m1id == 39 && Pion[p].m1id == 39 && Pion[p].id==8) || (Phi[ph].m1id == 40 && Pion[p].m1id == 40 &&      Pion[p].id==9)) && Phi[ph].m1brc == Pion[p].m1brc && Phi[ph].signal == true;

            if(signaldsp){
              hmdss->Fill(m);
              hmphis->Fill(mph);
              hestdss->Fill(estimator);
              haphipis->Fill(anglePhiPi);
              hakpkms->Fill(angleKpKm); 
              hedss->Fill(eDs);
              hesKpKms->Fill(sumekpkm);
              haphikps->Fill(anglePhiKp);
              haphikms->Fill(anglePhiKm);
              hapikps->Fill(anglePiKp);
              hapikms->Fill(anglePiKm);
              if(estcut)
               {
                  hmdsEstCuts->Fill(m);
		  haphipiEstCuts->Fill(anglePhiPi);
                  hakpkmEstCuts->Fill(angleKpKm);         
                  hedsEstCuts->Fill(eDs);
                  hesKpKmEstCuts->Fill(sumekpkm);
                  haphikpEstCuts->Fill(anglePhiKp);
                  haphikmEstCuts->Fill(anglePhiKm);
                  hapikpEstCuts->Fill(anglePiKp);
                  hapikmEstCuts->Fill(anglePiKm);
                  if(eDs >= 0.0 && eDs <= 9.0)
                  {
                    hmdss09->Fill(m);
                  }
                  else if(eDs > 9.0 && eDs <= 18.0)
                  {
                    hmdss918->Fill(m);
                  }
                  else if(eDs > 18.0 && eDs <= 27.0)
                  {
                    hmdss1827->Fill(m);
                  }
                  else if(eDs > 27.0 && eDs <= 36.0)
                  {
                    hmdss2736->Fill(m);
                  }
                  else if(eDs > 36.0 && eDs <= 45.6)
                  {
                    hmdss3645->Fill(m);
                  }
 
               }          
                         }
            else{
              hmdsb->Fill(m);
              if(estcut)
              { 
                if(eDs >= 0.0 && eDs <= 9.0)
                {
                  hmdsb09->Fill(m);
                }
                else if(eDs > 9.0 && eDs <= 18.0)
                {
                  hmdsb918->Fill(m);
                }
                else if(eDs > 18.0 && eDs <= 27.0)
                {
                  hmdsb1827->Fill(m);
                }
                else if(eDs > 27.0 && eDs <= 36.0)
                {
                  hmdsb2736->Fill(m);
                }
                else if(eDs > 36.0 && eDs <= 45.6)
                {
                  hmdsb3645->Fill(m);
                }
              }   
              hmphib->Fill(mph); 
              hestdsb->Fill(estimator);
              hakpkmb->Fill(angleKpKm); 
              haphipib->Fill(anglePhiPi);
              hedsb->Fill(eDs);	
              hesKpKmb->Fill(sumekpkm);
              haphikpb->Fill(anglePhiKp);
              haphikmb->Fill(anglePhiKm);
              hapikpb->Fill(anglePiKp);
              hapikmb->Fill(anglePiKm);

              if(estcut)
                 {
                  hmdsEstCutb->Fill(m);
                  hakpkmEstCutb->Fill(angleKpKm);
                  haphipiEstCutb->Fill(anglePhiPi); 
                  hedsEstCutb->Fill(eDs);
                  hesKpKmEstCutb->Fill(sumekpkm);
                  haphikpEstCutb->Fill(anglePhiKp);
                  haphikmEstCutb->Fill(anglePhiKm);
                  hapikpEstCutb->Fill(anglePiKp);
                  hapikmEstCutb->Fill(anglePiKm); 
  
                 }
            }
           }
