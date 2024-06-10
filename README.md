There are a few issues in your code that might be causing the table to not display any data. Here are the steps to fix the errors:

1. **Change `allUsers` to `data` in `useTable` Hook:** The `useTable` hook expects the `data` property instead of `allUsers`.

2. **Replace duplicate user IDs in initial data:** The initial data contains duplicate `userid` values. Each user should have a unique `userid`.

3. **Fix the display issue for sorted icons:** The sorted icons are using special characters that might not render properly. Use simpler text or icons.

4. **Ensure that data is being correctly fetched:** Ensure that the `allUsers` state is correctly populated from the API.

Here's the corrected version of your code:

```javascript
import React, { useEffect, useState } from 'react';
import { useTable, useSortBy, useGlobalFilter } from 'react-table';
import { useNavigate } from 'react-router-dom';
import EditUserModal from '../components/EditUserModal';

const GlobalFilter = ({ globalFilter, setGlobalFilter }) => {
  return (
    <span>
      Search:{' '}
      <input
        value={globalFilter || ''}
        onChange={e => setGlobalFilter(e.target.value || undefined)}
        placeholder="Search by name"
        className="p-2 mb-4 border border-gray-300 rounded-lg"
      />
    </span>
  );
};

const Users = () => {
  const [allUsers, setAllUsers] = useState([]);
  const navigate = useNavigate();

  useEffect(() => {
    const userData = async () => {
      try {
        const res = await fetch(`${import.meta.env?.VITE_BACKEND_URL}/admin/users`, {
          headers: {
            'Content-Type': 'application/json',
            'accesstoken': sessionStorage.getItem('accessToken')
          }
        });
        const d = await res.json();
        setAllUsers(d);
      } catch (error) {
        alert("error while admin users");
        console.log(error);
      }
    };

    userData();
  }, []);

  const initialData = React.useMemo(
    () => [
      {
        userid: 1,
        name: 'John Doe',
        email: 'john.doe@example.com',
        dob: '1980-01-01',
        invested: 50000,
        worth: 70000,
        profitLoss: 20000,
        nop: 3
      },
      {
        userid: 2,
        name: 'Jane Doe',
        email: 'jane.doe@example.com',
        dob: '1985-01-01',
        invested: 60000,
        worth: 80000,
        profitLoss: 20000,
        nop: 4
      }
    ],
    []
  );

  const [selectedUser, setSelectedUser] = useState(null);
  const [isModalOpen, setIsModalOpen] = useState(false);

  const handleEdit = (user) => {
    setSelectedUser(user);
    setIsModalOpen(true);
  };

  const handleSave = (updatedUser) => {
    setAllUsers(allUsers.map(user => (user.userid === selectedUser.userid ? { ...user, ...updatedUser } : user)));
    setIsModalOpen(false);
  };

  const handleRowClick = (user) => {
    navigate(`/admin/users/${user.userid}`);
  };

  const columns = React.useMemo(
    () => [
      { Header: 'Name', accessor: 'name' },
      { Header: 'Email', accessor: 'email' },
      { Header: 'Total Invested', accessor: 'invested' },
      { Header: 'Total Worth', accessor: 'worth' },
      { Header: 'Profit/Loss', accessor: 'profitLoss' },
      { Header: 'No. of Portfolios', accessor: 'nop' },
      {
        Header: 'Actions',
        accessor: 'actions',
        Cell: ({ row }) => (
          <div className="flex space-x-2">
            <button onClick={() => handleEdit(row.original)} className="bg-blue-500 text-white px-2 py-1 rounded">
              Edit
            </button>
          </div>
        )
      }
    ],
    []
  );

  const {
    getTableProps,
    getTableBodyProps,
    headerGroups,
    rows,
    prepareRow,
    state,
    setGlobalFilter
  } = useTable(
    { columns, data: allUsers.length ? allUsers : initialData },
    useGlobalFilter,
    useSortBy
  );

  const { globalFilter } = state;

  return (
    <div className="container mx-auto p-6 bg-white rounded-lg shadow relative">
      <div className="flex justify-between items-center mb-4">
        <h2 className="text-lg font-semibold">Users</h2>
        <button onClick={() => navigate('/editstocks')} className="bg-blue-500 text-white px-4 py-2 rounded-lg">
          Edit Stocks
        </button>
      </div>
      <GlobalFilter globalFilter={globalFilter} setGlobalFilter={setGlobalFilter} />
      <div className="overflow-x-auto">
        <table {...getTableProps()} className="min-w-full bg-white">
          <thead>
            {headerGroups.map(headerGroup => (
              <tr {...headerGroup.getHeaderGroupProps()}>
                {headerGroup.headers.map(column => (
                  <th
                    {...column.getHeaderProps(column.getSortByToggleProps())}
                    className="px-6 py-3 border-b-2 border-gray-300 bg-gray-100 text-left text-xs leading-4 font-medium text-gray-600 uppercase tracking-wider"
                  >
                    {column.render('Header')}
                    <span>
                      {column.isSorted
                        ? column.isSortedDesc
                          ? ' ▼'
                          : ' ▲'
                        : ''}
                    </span>
                  </th>
                ))}
              </tr>
            ))}
          </thead>
          <tbody {...getTableBodyProps()}>
            {rows.map(row => {
              prepareRow(row);
              return (
                <tr
                  {...row.getRowProps()}
                  className="hover:bg-gray-100 cursor-pointer"
                  onClick={() => handleRowClick(row.original)}
                >
                  {row.cells.map(cell => (
                    <td
                      {...cell.getCellProps()}
                      className="px-6 py-4 whitespace-no-wrap border-b border-gray-300"
                    >
                      {cell.render('Cell')}
                    </td>
                  ))}
                </tr>
              );
            })}
          </tbody>
        </table>
      </div>
      {isModalOpen && (
        <EditUserModal
          user={selectedUser}
          isOpen={isModalOpen}
          onClose={() => setIsModalOpen(false)}
          onSave={handleSave}
        />
      )}
    </div>
  );
};

export default Users;
```

Changes made:
1. Updated `useTable` hook to use `data` instead of `allUsers`.
2. Fixed initial data to use unique `userid` values.
3. Simplified sorted icons to use text characters '▼' and '▲'.

These changes should help ensure the table displays data correctly.