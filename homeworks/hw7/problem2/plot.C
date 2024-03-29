void plot(TString fName="pendulum.root")
{
	TFile *f = new TFile(fName, "READ");
	TH2D *h2d = (TH2D*) f->Get("hpendulum2d");
	
	h2d->SetTitle("Pendulum Histogram; Theta [rad]; Phi [rad]");
	
	// Make the plot esthetically better
    	h2d->SetMarkerStyle(kOpenCircle);
    	h2d->SetMarkerColor(kBlue);
    	
	auto mycanvas = new TCanvas();
	h2d->DrawCopy();
	mycanvas->Print("Pendulum Histogram of theta and theta'.png");
}
