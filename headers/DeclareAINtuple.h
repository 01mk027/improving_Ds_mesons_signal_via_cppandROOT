  //Declaring TNtuple
  TString tmvafilename = "files/tmvadata.root";
  TFile *tmvafile = new TFile(tmvafilename,"recreate");
  TNtuple *tmvadataS = new TNtuple("signal","signal","anglePhiPi:angleKpKm:eDs:sumekpkm:anglePhiKp:anglePhiKm:anglePiKp:anglePiKm");
  TNtuple *tmvadataB = new TNtuple("background","background","anglePhiPi:angleKpKm:eDs:sumekpkm:anglePhiKp:anglePhiKm:anglePiKp:anglePiKm");

