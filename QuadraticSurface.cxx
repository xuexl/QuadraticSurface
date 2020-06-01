#include <vtkSmartPointer.h>
#include <vtkQuadric.h>
#include <vtkSampleFunction.h>
#include <vtkContourFilter.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataMapper.h>
#include<vtkCamera.h>

#include<vtkNamedColors.h>
#include <vtkCubeAxesActor.h>
#include<vtkTextProperty.h>


namespace  {

    void createSphere(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createTuoYuanZhui(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createTuoQiu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createDanYe(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createSuangYe(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createTuoYuanPao(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createShuangQuPao(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createShuangQuZhu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createTuoYuanZhu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    void createPaoWuZhu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i);
    
}


int main(int, char *[])
{
    int numberOfViewPorts = 10;
    
    auto colors = vtkSmartPointer<vtkNamedColors>::New();    
    auto renderWindow =  vtkSmartPointer<vtkRenderWindow>::New();
    
    renderWindow->SetSize(300 * numberOfViewPorts, 300);
    double size = 1.0 / numberOfViewPorts;
    
    //
    createSphere(renderWindow, size, 0);
    createTuoYuanZhui(renderWindow, size, 1);
    createTuoQiu(renderWindow, size, 2);
    createDanYe(renderWindow, size, 3);
    createSuangYe(renderWindow, size, 4);
    createTuoYuanPao(renderWindow, size, 5);
    createShuangQuPao(renderWindow, size, 6);
    createShuangQuZhu(renderWindow, size, 7);
    createTuoYuanZhu(renderWindow, size, 8);
    createPaoWuZhu(renderWindow, size, 9);
  
    //
  auto renderWindowInteractor =  vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
   
  renderWindow->Render();
  renderWindow->SetSize(1000, 800);
  renderWindowInteractor->Start();	
 
  return EXIT_SUCCESS;
}

namespace  {

    void createSphere(vtkSmartPointer<vtkRenderWindow> rw, double s, int i)
    {
        // Create the quadric function definition
          //隐函数
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(1.0,1.0,1.0,0.,0.,0.,0.,0.,0.,-100.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 10);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);        
    }

    void createTuoYuanZhui(vtkSmartPointer<vtkRenderWindow> rw, double s, int i)
    {
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(1.0,1.0,-1.0,.0,.0,.0,.0,.0,.0,.0);
        
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);           
    }

    void createTuoQiu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i)
    {
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(1.0,2.0,3.0,.0,.0,.0,.0,.0,.0,-1.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);    
    }
    
    void createDanYe(vtkSmartPointer<vtkRenderWindow> rw, double s, int i){
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(10.0,10.0,-10.0,.0,.0,.0,.0,.0,.0,-1.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);            
    }
    
    void createSuangYe(vtkSmartPointer<vtkRenderWindow> rw, double s, int i){
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(10.0,-10.0,-10.0,.0,.0,.0,.0,.0,.0,-1.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);            
    }
    
    void createTuoYuanPao(vtkSmartPointer<vtkRenderWindow> rw, double s, int i){
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(10.0,20.0,.0,.0,.0,.0,.0,.0,-1.0,.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);            
    }
    
    void createShuangQuPao(vtkSmartPointer<vtkRenderWindow> rw, double s, int i){
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(10.0,-20.0,.0,.0,.0,.0,.0,.0,-1.0,.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);            
    }

    void createShuangQuZhu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i){
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(10.0,-20.0,.0,.0,.0,.0,.0,.0,.0,-1.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);            
    }
    
    void createTuoYuanZhu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i){
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(10.0,20.0,.0,.0,.0,.0,.0,.0,.0,-1.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        rw->AddRenderer(renderer);            
    }
    
    void createPaoWuZhu(vtkSmartPointer<vtkRenderWindow> rw, double s, int i){
        vtkSmartPointer<vtkQuadric> quadric =
          vtkSmartPointer<vtkQuadric>::New();
        quadric->SetCoefficients(1.0,.0,.0,.0,.0,.0,.0,2.0,.0,.0);
       
        // Sample the quadric function
        vtkSmartPointer<vtkSampleFunction> sample =
          vtkSmartPointer<vtkSampleFunction>::New();
        sample->SetSampleDimensions(100,100,100);
        sample->SetImplicitFunction(quadric);
        double xmin = -100, xmax=100, ymin=-100, ymax=100, zmin=-100, zmax=100;
//        sample->SetModelBounds(xmin, xmax, ymin, ymax, zmin, zmax);
       
        vtkSmartPointer<vtkContourFilter> contourFilter =
          vtkSmartPointer<vtkContourFilter>::New();
        contourFilter->SetInputConnection(sample->GetOutputPort());
        contourFilter->GenerateValues(1, 0, 100);
        contourFilter->Update();
        
        // Visualize
        vtkSmartPointer<vtkPolyDataMapper> mapper = 
          vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(contourFilter->GetOutputPort());
       
        vtkSmartPointer<vtkActor> actor = 
          vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
       
        vtkSmartPointer<vtkRenderer> renderer = 
          vtkSmartPointer<vtkRenderer>::New();
                
        renderer->AddActor(actor);
        renderer->SetBackground(.3, .6, .3); // Background color green
       
        renderer->ResetCamera();
        
        double viewport[4];
        viewport[0] = s * i;
        viewport[1] = 0.0;
        viewport[2] = s * (i + 1);
        viewport[3] = 1.0;
        renderer->SetViewport(viewport);
        
        //
        auto colors = vtkSmartPointer<vtkNamedColors>::New();
        vtkColor3d axis1Color = colors->GetColor3d("Salmon");
          vtkColor3d axis2Color = colors->GetColor3d("PaleGreen");
          vtkColor3d axis3Color = colors->GetColor3d("DodgerBlue");
        
        auto cubeAxesActor = vtkSmartPointer<vtkCubeAxesActor>::New();
        cubeAxesActor->SetUseTextActor3D(1);
        cubeAxesActor->SetBounds(contourFilter->GetOutput()->GetBounds());
        cubeAxesActor->SetCamera(renderer->GetActiveCamera());
        
        cubeAxesActor->GetTitleTextProperty(0)->SetColor(axis1Color.GetData());
//        cubeAxesActor->GetTitleTextProperty(0)->SetFontSize(48);
        cubeAxesActor->GetLabelTextProperty(0)->SetColor(axis1Color.GetData());
      
        cubeAxesActor->GetTitleTextProperty(1)->SetColor(axis2Color.GetData());
        cubeAxesActor->GetLabelTextProperty(1)->SetColor(axis2Color.GetData());
      
        cubeAxesActor->GetTitleTextProperty(2)->SetColor(axis3Color.GetData());
        cubeAxesActor->GetLabelTextProperty(2)->SetColor(axis3Color.GetData());
      
        cubeAxesActor->DrawXGridlinesOn();
        cubeAxesActor->DrawYGridlinesOn();
        cubeAxesActor->DrawZGridlinesOn();
    
        cubeAxesActor->SetGridLineLocation(cubeAxesActor->VTK_GRID_LINES_FURTHEST);
      
        cubeAxesActor->XAxisMinorTickVisibilityOff();
        cubeAxesActor->YAxisMinorTickVisibilityOff();
        cubeAxesActor->ZAxisMinorTickVisibilityOff();
      
        cubeAxesActor->SetFlyModeToStaticEdges();
        
        renderer->AddActor(cubeAxesActor);
        
        
        rw->AddRenderer(renderer);            
    }
    
}