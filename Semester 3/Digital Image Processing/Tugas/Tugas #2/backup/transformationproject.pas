unit TransformationProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  ComCtrls, CheckLst;

type

  { TtranformationForm }

  TtranformationForm = class(TForm)
    btnLoad: TButton;
    checkBox: TCheckBox;
    imgOriginal: TPaintBox;
    openDialog: TOpenDialog;
    TrackBar1: TTrackBar;
    TrackBar2: TTrackBar;
    TrackBar3: TTrackBar;
    procedure checkBoxChange(Sender: TObject);
  private

  public

  end;

var
  tranformationForm: TtranformationForm;

implementation

{$R *.lfm}

{ TtranformationForm }

end.

