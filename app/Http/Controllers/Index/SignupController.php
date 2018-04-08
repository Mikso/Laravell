<?php

namespace App\Http\Controllers\Index;

use Illuminate\Http\Request;
use App\Http\Controllers\Controller;
use App\Model\Signup\Usuario;


class SignupController extends Controller
{

    private $usuario;

    
      public function __construct(Usuario $usuario) { // Construtor do PHP, observe a barra dupla
          $this->usuario = $usuario;
         
      }
    




    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $title = 'SignUp'; // titulo da pagina
        return view('site.home.signup', compact('title')); // retorno a view
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //$dataForm = $request->all();

      //$insert = $this->usuario->insert($dataForm);
      return 'testando';
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
     
        $dataForm = $request->except('_token'); // capturo tudo, exceto o token
        
        $insert = $this->usuario->create($dataForm); // So vai inserir os dados que defini na model

        if($insert) // Se tiver inserido no db com sucesso, retorna o login senao...
            return 'Inserido';
            else
            return 'Não Inserido';

    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        //
    }
}
