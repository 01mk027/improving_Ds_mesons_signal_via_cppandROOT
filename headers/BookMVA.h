  Float_t anglePhiPi,angleKpKm,eDs,sumekpkm,anglePhiKp,anglePhiKm,anglePiKp,anglePiKm;
  TMVA::Tools::Instance();
  TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");
  reader->AddVariable("anglePhiPi",&anglePhiPi);
  reader->AddVariable("angleKpKm",&angleKpKm);
  reader->AddVariable("eDs",&eDs);
  reader->AddVariable("sumekpkm",&sumekpkm);
  reader->AddVariable("anglePhiKp",&anglePhiKp);
  reader->AddVariable("anglePhiKm",&anglePhiKm);
  reader->AddVariable("anglePiKp",&anglePiKp);
  reader->AddVariable("anglePiKm",&anglePiKm);
    
  double tmvacut = -0.02;
  TString method = "BDT";
  TString methodName = method + TString(" method");
  TString weightfile = TString("files/dataset/weights/TMVAClassification_") + method + TString(".weights.xml");
  reader->BookMVA( methodName, weightfile );    

