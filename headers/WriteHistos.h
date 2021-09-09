
  //Writing TNtuple which ll be classified
  tmvafile->cd();
  tmvadataS->Write();
  tmvadataB->Write();
  gDirectory->Purge();
  tmvafile->Close();
  
  myRoot->Write();
  gDirectory->Purge();
  myRoot->Close(); 
